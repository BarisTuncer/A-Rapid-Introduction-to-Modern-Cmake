+++
title = "Lab3"
description = ""
weight = 1
+++

[Lab3]:https://github.com/BarisTuncer/A-Rapid-Introduction-to-Modern-Cmake/tree/Lab3

Let's switch to **[Lab3]** branch.

We have created

* `Layer1` inside of which `log` and `mylib` libraries reside
* `Layer2` inside of which `csapp` library resides

Your task is to enforce the design principle below:

1. `driver` can access `mylib` but it can't access `csapp` 
2. `driver` can access `log`
3. `mylib`  can access `log`
4. `driver` can't acces `mylib`'s private headers