+++
title = "Lab3"
description = ""
weight = 1
+++

We have created

* `Layer1` inside of which `log` and `mylib` libraries reside
* `Layer2` inside of which `csapp` library resides

Your task is to enforce the design principle below:

1. `driver` can access `mylib` but it can't access `csapp` 
2. `driver` can access `log`
3. `mylib`  can access `log`
4. `driver` can't acces `mylib`'s private headers