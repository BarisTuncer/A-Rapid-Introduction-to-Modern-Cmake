# Format checking

`clang-format`  is an excellent tool to format C/C++/Java/JavaScript/Objective-C/Protobuf code. 

To install

* `sudo apt-get install clang-format`

To generate a `google` style `.clang-format`, run the following command in the terminal.

* `clang-format -style=google -dump-config > .clang-format`

To see the other options and learn what `clang-format` does be sure to check  **[ClangFormatStyleOptions](https://clang.llvm.org/docs/ClangFormatStyleOptions.html)**

[Thom]: https://github.com/ttroy50/cmake-examples/tree/master/04-static-analysis/clang-format 

## A useful script by **[Thom]**

I invite you have a look at **[Thom]**'s github page which has helpful cmake modules to check if your source code matches against your code style guidelines.

Thank you **Thom** for making this tool available for us!

To use his script, we simply add to following commands to our top level CMakeLists.txt. 

* `set(CLANG_FORMAT_BIN_NAME clang-format)` 
* `find_package(ClangFormat)`

In line 4 of `clang-format.cmake` by **[Thom]**, I also included `.c` files into the `CLANG_FORMAT_CXX_FILE_EXTENSIONS` list.

[CMakeLists]: CMakeLists.txt
In top level [CMakeLists], I made formatting optional and excluded the directories that I don't want to be formatted by updating the list `CLANG_FORMAT_EXCLUDE_PATTERNS` 

Otherwise his **[Thom]**'s script will format every `*[ch]` source file in the project folder.

After the build step, his script will generate 3 utilities called `format`, `format-check` and `format-check-changed`.
Clear explanations of what can be done with these utilities are given in the **[Thom]**'s github page. Basically 

* running `format` will format the files that you allowed for the format check.

* running `format-check` will check whether the files, that you allowed for the format check, obey the format style rules and return a failure if they don't.

* running `format-check-changed` will check the `git` status and return a failure, if any one of the changed files that you allowed for the format check, does not obey the format style rules. 

To be able to run `format-check-changed` utility you should give a permission to the scripts inside `cmake/scripts` to execute (via `chmod +x filename` for example)

Apparently, the most useful utility is `format`. Run it and see the difference via `git diff`. That's what I do.


