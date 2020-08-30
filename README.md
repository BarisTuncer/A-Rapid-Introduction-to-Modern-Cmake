# Format checking

`clang-format`  is an excellent tool to format C/C++/Java/JavaScript/Objective-C/Protobuf code. 

To install

* `sudo apt-get install clang-format`

To generate `.clang-format` from style `google` run the following command in the terminal.

* `clang-format -style=google -dump-config > .clang-format`

To see the other options and learn what `clang-format` does be sure to check  **[ClangFormatStyleOptions](https://clang.llvm.org/docs/ClangFormatStyleOptions.html)**

## A useful script by **ttroy50**

I invite you have a look at **[Thom](https://github.com/ttroy50/cmake-examples/tree/master/04-static-analysis/clang-format)**'s 
very useful cmake modules which are helpful to check if your source code matches against your code style guidelines.

Thank you **Thom** for making this tool available for us!

To use his script, we simply add to following commands to our top level CMakeLists.txt. 

* `set(CLANG_FORMAT_BIN_NAME clang-format)` 
* `find_package(ClangFormat)`

In line 4 of `clang-format.cmake` by `ttroy50`, I also included `c` files into the `CLANG_FORMAT_CXX_FILE_EXTENSIONS` list

To exclude the directories that I don't want to be formatted, I also updated the list `CLANG_FORMAT_EXCLUDE_PATTERNS` at the beginning of
`clang-format.cmake`:

`set(CLANG_FORMAT_EXCLUDE_PATTERNS 
    ${CMAKE_SOURCE_DIR}/build
    ${CMAKE_SOURCE_DIR}/cmake
    ${CMAKE_SOURCE_DIR}/Csapp
    ${CMAKE_SOURCE_DIR}/Log
)`

Otherwise his script will format every `*[ch]` source file
in the project folder.

After the build step, his script will generate 3 executable called `format`, `format-check` and `format-check-changed`.
Clear explanations of what can be done with these executable are given in the link above. 


