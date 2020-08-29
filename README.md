# Rapid introduction to Modern CMake with hands on labs

The aim of this tutorial is to provide a rapid introuduction to Modern CMake by a relatively non-trivial example and clarify the meanings of `PUBLIC` and `PRIVATE` keywords which is confusing to the beginners.  

I divided this tutorial into 3 steps and provided 3 labs to test your knowledge.

To make this tutorial joyful I used 2 external libraries.

1 - `csapp.h` : This library is developed for `Computer Systems: A Programmer's Perspective` book by Randal E. Bryant and David R. O'Hallaron,
which contains wrappers for some system functions in C and also implementation of robust IO functions. It is publicly available from the website of the book : https://csapp.cs.cmu.edu/. The reason I chose this library is that you need to link it with `pthread` library.

Thank you Randal E. Bryant and David R. O'Hallaron for making this library accessible for us!

2- `log.h`: This library is a simple usage logging library developed by `rxi` and publicly available at https://github.com/rxi/log.c/blob/master/README.md.
The reason I chose this library is that you need to compile it with the definition `DLOG_USE_COLOR` to get a colorful logging output. 

Thank you `rxi` for making this library accessible for us.

## Tutorial Steps and Labs

Tutorial steps as well as the labs and their solutions are in the branches of this repo. You can access them by changing the branch from the `master` to the one of the branches above or via  `git checkout`. Below is the schedule.

* In `Step1`, we will compile a simple `Hello Modern CMake` program.

* In `Lab1`, you will add another executable to the project of `Step1`

* In `Step2`, we will add `log` library into our program.

* In `Lab2`, you will create `Libraries` folder inside of which `log` and `csapp` libraries reside.

* In `Step3`, we will add `mylib` library into our project which will depend on `csapp` library satisfying the design policy described below. 

* In `Lab3`, you will create `Layer1` folder which contains `log` and `mylib` libraries, `Layer2` folder which contains `csapp` library. So, the goal is to enforce `driver` to be able to access only `Layer1` which depends on `Layer2`. `driver` should not be able to access resources of `Layer2`. 

After 3 easy steps, we will see how easy to keep modularity in our code with the help of `Modern CMake`. 

## Design policy

Our aim in `Step 3` is: (--> means can access)

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

