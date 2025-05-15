cmake_minimum_required(VERSION 3.28)

project(gpanel)

set(CMAKE_CXX_STANDARD 20)


include_directories(include)
include_directories(../common)


set(CMAKE_AUTOMOC ON)  # Ensures MOC is processed automatically
set(CMAKE_AUTOUIC ON)  # Required if using Qt Designer files (.ui)
set(CMAKE_AUTORCC ON)  # Required if using Qt resources (.qrc)


find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

file(GLOB_RECURSE SRC_FILES src/*.cpp include/*.hpp)

add_executable(gpanel app.cpp ${SRC_FILES})


target_link_libraries(gpanel Qt5::Core Qt5::Gui Qt5::Widgets)

#set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_EXE_LINKER_FLAGS "-Os")
