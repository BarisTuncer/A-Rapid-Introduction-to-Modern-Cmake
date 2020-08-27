# Non Trivial CMake Example

The aim of this tutorial is to describe the usage of PUBLIC and PRIVATE keywords of Modern CMake and clarify
the meanings of this keywords.

To make this tutorial joyful I used 2 external libraries.

1 - csapp.h : This library is developed for CSAPP book which contains wrappers for some system functions in C
and also implementation of robust IO functions. It is publicly available from the website of the book : https://csapp.cs.cmu.edu/ 
The reason I chose this library is that you need to link it with pthread library via `-pthread` option.

2- log.h: This library is a simple usage logging library developed by rxi and publicly available  https://github.com/rxi/log.c/blob/master/README.md
The reason I chose this library is that you need to compile with `-DLOG_USE_COLOR` to get a colorful logging output.
