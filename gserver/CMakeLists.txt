cmake_minimum_required(VERSION 3.28)

project(xserver)

find_package(OpenSSL REQUIRED)

include_directories(include)

include_directories(../common)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(xserver main.cpp ${SRC_FILES})

target_link_libraries(xserver OpenSSL::SSL OpenSSL::Crypto)
