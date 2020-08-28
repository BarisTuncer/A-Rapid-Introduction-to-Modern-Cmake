# The usage of PUBLIC and PRIVATE keywords in Modern CMake

The aim of this tutorial is to describe the usage of `PUBLIC` and `PRIVATE` keywords of Modern CMake and clarify
the meanings of these keywords.

To make this tutorial joyful I used 2 external libraries.

1 - csapp.h : This library is developed for Computer Systems: A Programmer's Perspective book by Randal E. Bryant and David R. O'Hallaron,
which contains wrappers for some system functions in C and also implementation of robust IO functions. It is publicly available from the website of the book : https://csapp.cs.cmu.edu/. The reason I chose this library is that you need to link it with pthread library via `-pthread` option. Thank you Randal E. Bryant and David R. O'Hallaron for making this library accessible for us!

2- log.h: This library is a simple usage logging library developed by rxi and publicly available at https://github.com/rxi/log.c/blob/master/README.md.
The reason I chose this library is that you need to compile with `-DLOG_USE_COLOR` to get a colorful logging output. Thank you rxi for making this library accessible for us.

## Tutorial Steps

Tutorial steps are in branches of this repo. You can access them by changing the branch from the `master` to the one of the branches above or via 
`git checkout`. Explanation of Steps are given in the README files of the branches.

* In `Step1`, we will compile a simple "Hello Modern CMake" program.

* In `Step2`, we will add log library into our program.

* In `Step3`, we will add `mylib` library into our project which will depend on `csapp` library. 

We enforce the following design policy in Step 3.  

## Design policy

Our aim in `Step 3` is: 

* to build a `driver` which uses a function `F` implemented by mylib : `driver --> mylib`
* mylib implements `F` by using `csapp` library functions : `mylib --> csapp`
* driver needs to access `mylib` and use `F` but driver should not be able to access 
  `csapp` library : `driver --x--> csapp`
* `mylib` has a helper function `G` that is used to implement `F`. But `G` shouldn't be 
  accessible to `driver`. : `driver --x--> mylib's private headers`
* `mylib` should not be able to access `log` library: `mylib --X--> log`     
* So, we simply want to make `mylib-->csapp` dependency private!

 Below is the summary of our design policy

 * `driver --> mylib ---> csapp --> pthread` 
 
 * `driver --> log`

 * `driver --X--> csapp`

 * `mylib --X--> log`       

