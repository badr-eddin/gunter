cmake_minimum_required(VERSION 3.28)

project(gserver)

find_package(OpenSSL REQUIRED)

include_directories(include)

include_directories(../common)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(gserver main.cpp ${SRC_FILES})

target_link_libraries(gserver OpenSSL::SSL OpenSSL::Crypto)
