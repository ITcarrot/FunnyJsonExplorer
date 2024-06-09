cmake_minimum_required(VERSION 3.1)

project(FunnyJsonExplorer VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

aux_source_directory(src SRC_FILE)

add_executable(fje ${SRC_FILE})

target_include_directories(fje PRIVATE include/)
