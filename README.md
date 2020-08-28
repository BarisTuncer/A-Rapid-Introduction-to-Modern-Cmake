# PRIVATE vs PUBLIC

Our aim in `Step 3` is to describe the usage of `PUBLIC` and `PRIVATE` keywords of Modern CMake and clarify
their meanings. In this section we want to:

1. build a `driver` which uses a function `F` implemented by mylib : `driver --> mylib`
2. mylib implements `F` by using `csapp` library functions : `mylib --> csapp`
3. driver needs to access `mylib` and use `F` but driver should not be able to access 
  `csapp` library : `driver --x--> csapp`
4. `mylib` has a helper function `G` that is used to implement `F`. But `G` shouldn't be 
  accessible to `driver`. : `driver --x--> mylib's private headers`
5. `csapp` should not be able to access `log` library: `csapp --X--> log`     
6. So, we simply want to make `mylib-->csapp` dependency private!

 Below is the summary of our design policy

 * `driver --> mylib ---> csapp --> pthread` 
 
 * `driver --> log`

 * `driver --X--> csapp`

 * `csapp --X--> log`       

# Targets are like objects

CMake treats targets as object-like entities and uses the targets properties (members). Some of the properties of targets are: 

1. `INCLUDE_DIRECTORIES`: List of preprocessor include file search directories.

2. `COMPILE_DEFINITIONS`: Preprocessor definitions for compiling a target’s sources. (LIKE: `UNIT_TESTING=1` or `IO_TEST=1`)

3. `COMPILE_OPTIONS`: List of options to pass to the compiler. (LIKE: `Werror` `Wall` `Wextra`)
    
4. ... There are many: See  https://cmake.org/cmake/help/latest/manual/cmake-properties.7.html#target-properties 


These properties (members) manipulated by (member-functions like ) 

* `target_include_directories()` 

* `target_compile_definitions()`

* `target_compile_options()`

The scope of theses properties are defined by the keywords `PUBLIC-PRIVATE`:

(There is one more keyword `INTERFACE`: See the discussion: https://stackoverflow.com/questions/26243169/cmake-target-include-directories-meaning-of-scope )

But what do we mean by scope?

When you use the `PRIVATE` keyword in `target_include_directories(<target> ...)` and alike, 
you tell CMake to populate members of `<target>`

When you use the `PUBLIC` keyword in `target_include_directories(<target>)` and alike, 
you tell CMake 

* to populate members of `<target>` and also 

* tell CMake to append members of `<target>` to any `<client>` members of which links `<target>`. 

* If we use `PRIVATE` this won't be the case.

# driver can access mylib and log

Now we take a look at `Driver/CMakeLists.txt`. When the macros expanded we have 

* `target_link_libraries(driver PRIVATE mylib`) and  `target_link_libraries(driver PRIVATE log`).

This enables `driver`'s access to `mylib` and `log`'s public resources, i.e., `main.c` can include `mylib.h` and `log.h` 
and use these libraries.

Here `PRIVATE` or `PUBLIC` is not important since `driver` as an executible is the final destination

Hence we have `driver-->mylib` and `driver-->log`

# driver cannot access csapp and mylib's private headers

Now we take a look at `Mylib/CMakeLists.txt`. When the macros expanded we have 

* `target_include_directories(mylib PUBLIC Mylib/include)`.

Any `client` that links `mylib` can acces the public headers of `mylib` inside the folder `Mylib/include` , but *cannot* access it's private headers (and sources) residing inside `MyLib/src`

**Exp**: Since `driver` links `mylib`, `main.c` can access `mylib.h` but it cannot access `mylib_provate.h`.
To convince yourself, uncomment `#include "mylib_provivate` in `main.c` and see what happens!


* `target_link_libraries(mylib PRIVATE csapp)`

Any client that links `mylib` *cannot* access the properties of `csapp`.

**Exp**: `main.c` can access `mylib.h` and `mylib.c` can access `csapp.h`. But `main.c` cannot access `csapp.h`. 
Uncomment `#include "csapp.h` in `main.c` and see what happens!

Hence we have `driver --X--> csapp`


# csapp cannot access log

Also,

* `csapp.c` cannot access `log.h` since it didn't link `log` library.


# Breaking the law

Now, let's break the design principle and link mylib to csapp publicly!

* If we declare `target_link_libraries(mylib PUBLIC csapp)`

Then any client that links `mylib` can access the properties of `csapp`.

**Exp**: `main.c` can access `mylib.h` and `mylib.c` can access `csapp.h`. Now `main.c` can access `csapp.h`. 
Uncomment `#include "csapp.h` in `main.c` and see that there won't be any error!

