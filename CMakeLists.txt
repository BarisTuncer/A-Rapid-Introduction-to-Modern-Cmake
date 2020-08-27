cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
project(NonTrivialCMakeExample)
set(CMAKE_BUILD_TYPE Debug)
add_subdirectory(Driver)
add_subdirectory(Log)

# int this example

###  driver ---PRIVATE (or PUBLIC)---> log

