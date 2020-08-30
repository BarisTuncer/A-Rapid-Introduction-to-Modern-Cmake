cmake_minimum_required(VERSION 3.18)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

project(NonTrivialCMakeExample)
add_compile_options(-Wall -Wextra)
add_subdirectory(Log)
add_subdirectory(Csapp)
add_subdirectory(Mylib)
add_subdirectory(Driver)


# Set the searching location for cmake 'include' locations
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules
                      ${CMAKE_MODULE_PATH}
                      )

# Include the dependency-graph module
include(dependency-graph)
gen_dep_graph("pdf")

option(ENABLE_FORMATTING "clang-format formatting" ON)
if(ENABLE_FORMATTING)
    set(CLANG_FORMAT_EXCLUDE_PATTERNS 
        ${CMAKE_SOURCE_DIR}/build
        ${CMAKE_SOURCE_DIR}/cmake
        ${CMAKE_SOURCE_DIR}/Csapp
        ${CMAKE_SOURCE_DIR}/Log
    )
    foreach(folder ${CLANG_FORMAT_EXCLUDE_PATTERNS})
        message(STATUS "Disabling " ${folder} " for clang-format")
    endforeach()
    set(CLANG_FORMAT_BIN_NAME clang-format)
    find_package(ClangFormat)
endif()