# Sol 2

As you can see, solution is surprisingly simple. Below is the summary:

* `add_subdirectory(Libraries)` and `add_subdirectory(Driver)` to top level CMakeLists.txt

*  Create a new `Libraries/CMakeLists.txt` and include `add_subdirectory(Csapp)` `add_subdirectory(Log)`

*  Update the `Csapp/CMakeLists.txt` and `Log/CMakeLists.txt` to create the libraries in a way we did in Step 2 !

Thank you CMake!