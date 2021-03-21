+++
title = "Step2: Hello Mylib"
description = ""
weight = 2
+++
[Step2]:https://github.com/BarisTuncer/A-Rapid-Introduction-to-Modern-Cmake/tree/Step2
[Step2/Log]:https://github.com/BarisTuncer/A-Rapid-Introduction-to-Modern-Cmake/tree/Step2/Log
[Step2/CMakeLists.txt]:https://github.com/BarisTuncer/A-Rapid-Introduction-to-Modern-Cmake/blob/Step2/CMakeLists.txt
[Step2/Log/CMakeLists.txt]:https://github.com/BarisTuncer/A-Rapid-Introduction-to-Modern-Cmake/blob/Step2/Log/CMakeLists.txt
[Step2/Driver/main.c]:https://github.com/BarisTuncer/A-Rapid-Introduction-to-Modern-Cmake/blob/Step2/Driver/main.c

Let's switch to **[Step2]** branch.

Our aim is to include the **[Step2/Log]** library into our project. Below are the Steps.

The meanings of `PUBLIC` and `PRIVATE` keywords will be investigated in `Step3` of the tutorial.

## Hello loglib

* As a first step we include `add_subdirectory(Log)` into our top level **[Step2/CmakeLists.txt]**

## Add a CMakeLists into the Log directory

* CMake is now checking **[Step2/Log/CmakeLists.txt]** inside **[Step2/Log]** folder.

* `project(log)` : We treat building the log library as a sub-project and declare it

* `add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCE_DIR}/src/log.c)` : Unless there is a good reason we want shared libraries. The name of the library will be `loglib`.
It could be static by using `STATIC` instead of `SHARED`.

**Warning:** `PRIVATE` and `PUBLIC` keywords loose their meanings in case of static libraries. The meanings of `PUBLIC` and `PRIVATE` keywords will be investigated in `Step3`.


* `target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)` :  Announce the headers to the ones *who are linking* this lib. 
By this way **[Step2/Driver/main.c]** will simply declare `#include "log.h"` to get the taste of `loglib`. Note that we don't need to use relative paths!

* `target_compile_definitions(${PROJECT_NAME} PRIVATE LOG_USE_COLOR)` : To be able to see logs in color, we need to compile with `LOG_USE_COLOR` definition.
Withour CMake we would use `-DLOG_USE_COLOR` while compiling.

## Ready to build

We are ready to build our project!

* `mkdir build`

* `cd build`

* `cmake ..`

* `make`
