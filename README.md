# Dependency Graph

[CMake graphviz options]: https://cmake.org/cmake/help/latest/module/CMakeGraphVizOptions.html
[Graphviz]: https://graphviz.org/

CMake can generate [Graphviz] files showing the dependencies between the targets in a project, as well as external libraries which are linked against.

You can get more information at **[CMake graphviz options]**

To install [Graphviz]

* `sudo apt-get update`
* `sudo apt-get install graphviz`

When running CMake with the `--graphviz=foo.dot` option, it produces:

* a `foo.dot` file, showing all dependencies in the project

* a `foo.dot.<target>` file for each target, showing on which other targets it depends

* a `foo.dot.<target>.dependers` file for each target, showing which other targets depend on it

Those `.dot` files can be converted to images using the `dot` command from the [Graphviz] package:

`dot -Tpng -o foo.png foo.dot`

The different dependency types `PUBLIC`, `INTERFACE` and `PRIVATE` are represented as solid, dashed and dotted edges.

[StableCoder]: https://github.com/StableCoder/cmake-scripts

## A useful script by **[StableCoder]**

You can create a dependency graph of your project in very simple way by the CMake module developed by **[StableCoder]**

Thank you George for making this awesome scripts available for us!

Note that cmake-scripts by **[StableCoder]** under the `Apache License`.

Like `MIT Licence`, `Apache License` is also a permissive license. However, it has stringent terms when it comes to modifications. 
It requires you to explicitly list out all the modifications that you’ve done in the original software, i.e., you’re required to preserve modification notices.

[About Licenses]: https://resources.whitesourcesoftware.com/blog-whitesource/top-10-apache-license-questions-answered 
To learn more about the differences between `MIT` and `Apache` licenses, see for example, [About Licenses]

## Set the searching location for cmake 'include' locations

First create a `cmake/modules` folder on top level of your project and include `dependency-graph.cmake`
module inside of it.

Next include `set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/scripts)` into the top level project. This will inform cmake where
to search for cmake modules.

## Include dependency-graph module

[CMakeLists]: CMakeLists.txt

`dependency-graph` script aims to generate a dependency graph of a single project. Now inside of your top level **[CMakeLists]**

1. `include(dependency-graph)`. This will include the module `dependency-graph` in the directory `cmake/scripts`

2. `gen_dep_graph("png")` This will generate an executable `dep-graph-${PROJECT_NAME}`.

You need to run the executable to see the generated file, which is of type `png` in our case. You could choose `pdf` or any of your favorite format.

Inside **[CMakeLists]**, I made this step optional.








