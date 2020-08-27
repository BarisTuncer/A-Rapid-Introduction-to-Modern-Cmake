cmake_minimum_required(VERSION 3.18)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

project(NonTrivialCMakeExample)
#Adds options to the compilation of source files.
# NOTE: This is global. Act for all targets in the current directory and below that are added after this command is invoked
add_compile_options(-Wall -Wextra)
add_subdirectory(Driver)

# In this example we will simply compile driver 

