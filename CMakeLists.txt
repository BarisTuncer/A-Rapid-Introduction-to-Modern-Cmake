cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
project(NonTrivialCMakeExample)
set(CMAKE_BUILD_TYPE Debug)
add_subdirectory(Csapp)
add_subdirectory(Mylib)
add_subdirectory(Driver)
add_subdirectory(Log)

# int this example

###  driver ---PRIVATE (or PUBLIC)---> mylib ---PRIVATE---> csapp ---PUBLIC---> pthread
###    |
###    v
###   log

#[[
    1 - driver can access mylib but it can't access libcsapp unless mylib links libcsapp PUBLIC'ly
    2 - driver can't acces mylib's private headers even if mylib links libcsapp PUBLIC'ly
    3 - drive can access liblog but libcsapp can't unless it links it
]]

