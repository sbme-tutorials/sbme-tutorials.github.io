cmake_minimum_required(VERSION 2.8)

project(linkedlists)

add_executable(std_ll main_std.cpp)
add_executable(dll1 main_dll1.cpp DLL1.hpp)
add_executable(dll2 main_dll2.cpp DLL2.hpp)
add_executable(dll3 main_dll3.cpp DLL3.hpp)


find_package(tabulate)
if(NOT tabulate_FOUND)
    include(ExternalProject)
    set(tabulate_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/tabulate-install")
    ExternalProject_Add(tabulate
        URL https://github.com/sbme-tutorials/sbme-tutorials.github.io/raw/master/2020/data-structures/snippets/tabulate.zip
        SOURCE_DIR  "${CMAKE_CURRENT_BINARY_DIR}/tabulate-src"
        BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/tabulate-bin"
        INSTALL_DIR "${tabulate_INSTALL_DIR}"
        CMAKE_ARGS "-DCMAKE_C_FLAGS=${CMAKE_C_FLAGS}"
        "-DCMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}"
        "-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}"
        "-DCMAKE_INSTALL_PREFIX=${tabulate_INSTALL_DIR}")
    set(tabulate_INCLUDE "${tabulate_INSTALL_DIR}/include")
    add_dependencies(std_ll tabulate)
    add_dependencies(dll3 tabulate)
endif()

target_include_directories(std_ll PRIVATE ${tabulate_INCLUDE})
target_include_directories(dll3 PRIVATE ${tabulate_INCLUDE})

set_target_properties(std_ll  PROPERTIES CXX_STANDARD 17 CXX_EXTENSIONS OFF)
set_target_properties(dll1  PROPERTIES CXX_STANDARD 17 CXX_EXTENSIONS OFF)
set_target_properties(dll2  PROPERTIES CXX_STANDARD 17 CXX_EXTENSIONS OFF)
set_target_properties(dll3  PROPERTIES CXX_STANDARD 17 CXX_EXTENSIONS OFF)
