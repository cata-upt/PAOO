cmake_minimum_required(VERSION 3.10)
project(exe VERSION 1.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_subdirectory(lib)

add_executable(exe main.cxx)

link_directories(lib)

target_link_libraries(exe PUBLIC lib)

target_include_directories(exe PUBLIC 
                            "${PROJECT_BINARY_DIR}" 
                            "${PROJECT_SOURCE_DIR/lib}"
                            )