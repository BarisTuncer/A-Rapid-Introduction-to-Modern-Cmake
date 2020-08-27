# Hello loglib

Our aim is to include log library into our project. Below are the Steps.

## Update the top level CMakeLists 

* As a first step we include `add_subdirectory(Log)` into our top level **[`CmakeLists.txt`](CMakeLists.txt)**

## Add a CMakeLists into the Log directory

* CMake is now checking **[`CmakeLists.txt`](Log/CMakeLists.txt)** inside `Log` folder.

* `project(log)` : We treat building the log library as a sub-project and declare it

* `add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCE_DIR}/src/log.c)` : Unless there is a good reason we want shared libraries.
It could be static by using `STATIC` instead of `SHARED`. [**Warning**] `PRIVATE` and `PUBLIC` keywords lose their meanings in case of static libraries.
The name of the library will be `loglib`.

* `target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)` :  Announce the headers to the ones *who are linking* this lib. 
By this way **[main.c](Driver/main.c)** will simply declare `#include "log.h"`to get the taste of `loglib`. Note that we don't need to use relative paths!

* `target_compile_definitions(${PROJECT_NAME} PRIVATE LOG_USE_COLOR)` : To be able to see logs in color, we need to compile with `LOG_USE_COLOR` definition.
Withour CMake we would use `-DLOG_USE_COLOR` while compiling.

## Ready to build

We are ready to build our project!

* `mkdir build`

* `cd build`

* `cmake ..`

* `make`
