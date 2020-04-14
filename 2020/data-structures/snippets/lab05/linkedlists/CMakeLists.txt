cmake_minimum_required(VERSION 2.8)

project(linkedlists)

add_executable(${PROJECT_NAME} main.cpp LL.hpp)

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
    add_dependencies(${PROJECT_NAME}  tabulate)
endif()

target_include_directories(${PROJECT_NAME} PRIVATE ${tabulate_INCLUDE})
set_target_properties(${PROJECT_NAME}  PROPERTIES CXX_STANDARD 17 CXX_EXTENSIONS OFF)
