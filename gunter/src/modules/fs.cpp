#include "modules/fs.hpp"
#include "utils/com.hpp"

std::string fs::change_dir(std::string path) {
    LPCTSTR lpPath = path.c_str();

    // If the function succeeds, then the return value is non-zero.
    if (!SetCurrentDirectory(lpPath)) {
        return com::make_response("error", "?");
    } else {
        return com::make_response("info", fs::current_work_dir());
    }
}
std::string fs::current_work_dir() {
    char buffer[MAX_PATH];
    
    // If the function fails, the return value is zero.
    DWORD gwd_ret = GetCurrentDirectoryA(MAX_PATH, buffer);

    if (gwd_ret == 0) {
        return com::make_response("error", "?");
    }

    return com::make_response("info", std::string(buffer) + '\\');
}


std::string fs::create_dir(std::string name) {
    // If the function succeeds, the return value is nonzero.
    if (!CreateDirectoryA(name.c_str(), NULL)) {
        return com::make_response("error", "?");
    } else {
        return com::make_response("info", "directory " + name + " created.");
    }
}
std::string fs::create_file(std::string name) {
    // If the function fails, the return value is INVALID_HANDLE_VALUE.

    HANDLE handle = CreateFileA(
        name.c_str(),  // filename
        GENERIC_READ | GENERIC_WRITE,  // permissions
        0,  //Prevents other processes from modification, until the handle is closed. 
        NULL, // the handle returned cannot be inherited by any child processes.
        CREATE_NEW, // if already exists, the function fails.
        FILE_ATTRIBUTE_NORMAL, // normal attributes, *hidden can be use too
        NULL // file template (no idea what it is)
    );

    if (handle == INVALID_HANDLE_VALUE) {
        return com::make_response("error", "?");
    } else {
        // close file handle
        CloseHandle(handle);
        return com::make_response("info", "file " + name + " created.");
    }

}


std::string fs::delete_dir(std::string path) {
    // If the function succeeds, the return value is nonzero.
    if (!RemoveDirectoryA(path.c_str())) {
        return com::make_response("error", "?");
    } else {
        return com::make_response("info", "directory " + path + " removed.");
    }
}
std::string fs::delete_file(std::string path) {
    // If the function succeeds, the return value is nonzero.
    if (!DeleteFileA(path.c_str())) {
        return com::make_response("error", "?");
    } else {
        return com::make_response("info", "file " + path + " removed.");
    }
}

std::string fs::copy_file(std::string src, std::string dst) {
    // If the function succeeds, the return value is nonzero.

    if (CopyFileA(
        src.c_str(),
        dst.c_str(),
        TRUE // if the dst already exists, the function fails
      )) {
        return com::make_response("error", "?");
    } else {
        return com::make_response("info", "copied " + src + " -> " + dst);
    }
}
std::string fs::copy_dir(std::string src, std::string dst) {
    //  TODO: implement
    return com::make_response("warn", "not implemented yet!");
}


std::string fs::move_file(std::string src, std::string dst) {
    // If the function succeeds, the return value is nonzero.

    if (!MoveFileA(
        src.c_str(),
        dst.c_str()
      )) {
        return com::make_response("error", "?");
    } else {
        return com::make_response("info", "moved " + src + " -> " + dst);
    }
}
std::string fs::move_dir(std::string src, std::string dst) {
    //  TODO: implement
    return com::make_response("warn", "not implemented yet!");
}

std::string fs::find_file(std::string name_rule, std::string root) {
    // TODO: not recursive
    return fs::list_dir(root, name_rule);
}


std::string fs::list_dir(std::string path) {
    return fs::list_dir(path, "*");
}

std::string fs::list_dir(std::string path, std::string rule = "*") {
    // enusre that the path ends with backslash

    if (!path.empty() && path.back() != '\\') {
        path += "\\";
    }

    std::string search_path = path + rule;
    WIN32_FIND_DATA find_data;
    HANDLE h_find = FindFirstFileA(search_path.c_str(), &find_data);

    if (h_find == INVALID_HANDLE_VALUE) {
        return com::make_response("info", "{}");  // empty/not-directory/not-exists
    }

    picojson::array list;

    // Headers
    list.push_back(picojson::value(picojson::array{
        picojson::value("name"),
        picojson::value("size"),
        picojson::value("modified"),
        picojson::value("type"),
        picojson::value("fullpath")
    }));

    do {
        picojson::array item;
        
        // ============= file name/path
        std::string file_name = find_data.cFileName;
        std::string full_path = path + file_name;

        // skip "." and ".."
        if (file_name == "." || file_name == "..") continue;

        item.push_back(picojson::value(file_name));

        // ============= file size
        // if the item is directory ignore size
        if (find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            item.push_back(picojson::value((double)(0)));
        } else {
            LARGE_INTEGER fsize;
            fsize.LowPart = find_data.nFileSizeLow;
            fsize.HighPart = find_data.nFileSizeHigh;
            item.push_back(picojson::value(static_cast<double>(fsize.QuadPart))); 
        }

        // ============= modification time
        FILETIME ftime = find_data.ftLastWriteTime;
        SYSTEMTIME stime;

        FileTimeToSystemTime(&ftime, &stime);

        char time_buffer[20];
        snprintf(time_buffer, sizeof(time_buffer), "%04d-%02d-%02d %02d:%02d:%02d",
             stime.wYear, stime.wMonth, stime.wDay, 
             stime.wHour, stime.wMinute, stime.wSecond);

        item.push_back(picojson::value(time_buffer));

        // ============= file type
        item.push_back(picojson::value(
            (find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ? "folder" : "file"
        ));
        
        // ============= full path
        item.push_back(picojson::value(full_path));

        // add one file to the list
        list.push_back(picojson::value(item));

    } while (FindNextFileA(h_find, &find_data));

    FindClose(h_find);

    return com::make_response("info", picojson::value(list).serialize());
}
