cmake_minimum_required(VERSION 2.8)

project(linkedlists)

add_executable(${PROJECT_NAME} main.cpp CovidItem.hpp)

find_package(tabulate)
if(NOT tabulate_FOUND)
    include(ExternalProject)
    include(GNUInstallDirs)
    set(tabulate_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/tabulate-install")
    ExternalProject_Add(tabulate
                    URL tabulate.zip
                    SOURCE_DIR  "${CMAKE_CURRENT_BINARY_DIR}/tabulate-src"
                    BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/tabulate-bin"
                    INSTALL_DIR "${tabulate_INSTALL_DIR}"
                    CMAKE_ARGS "-DCMAKE_C_FLAGS=${CMAKE_C_FLAGS}"
                               "-DCMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}"
                               "-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}"
                               "-DCMAKE_INSTALL_PREFIX=${tabulate_INSTALL_DIR}"
                    )
     set(tabulate_LIB "${tabulate_INSTALL_DIR}/${CMAKE_INSTALL_LIBDIR}/${CMAKE_STATIC_LIBRARY_PREFIX}tabulate${CMAKE_STATIC_LIBRARY_SUFFIX}")
     set(tabulate_INCLUDE "${tabulate_INSTALL_DIR}/include")
     add_dependencies(${PROJECT_NAME}  tabulate)
endif()

message( "${tabulate_INCLUDE}")


target_link_libraries(${PROJECT_NAME} INTERFACE ${tabulate_LIB})
target_include_directories(${PROJECT_NAME} INTERFACE ${tabulate_INCLUDE})
