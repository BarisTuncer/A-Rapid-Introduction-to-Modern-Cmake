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
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
# Include the dependency-graph module
include(dependency-graph)
gen_dep_graph("pdf")




