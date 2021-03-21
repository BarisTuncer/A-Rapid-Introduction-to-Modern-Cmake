+++
title = "Lab1"
description = ""
weight = 1
+++
[Lab1]:https://github.com/BarisTuncer/A-Rapid-Introduction-to-Modern-Cmake/tree/Lab1
[Lab1/Driver]:https://github.com/BarisTuncer/A-Rapid-Introduction-to-Modern-Cmake/tree/Lab1/Driver
[Lab1/Driver/anothermain.c]:https://github.com/BarisTuncer/A-Rapid-Introduction-to-Modern-Cmake/blob/Lab1/Driver/anothermain.c
[Lab1/Driver/CmakeLists.txt]:https://github.com/BarisTuncer/A-Rapid-Introduction-to-Modern-Cmake/blob/Lab1/Driver/CMakeLists.txt

Let's switch to **[Lab1]** branch.

We have included another file **[Lab1/Driver/anothermain.c]** inside the **[Lab1/Driver]** folder.

With this current form of the project, CMake will create only the executable called `main`. Convince yourself by building the project that there is only one executable `main` will be generated. Run it.

Your task is to add another executible called `anothermain` whose source file is **[Lab1/Driver/anothermain.c]** , by updating **[Lab1/Driver/CMakeLists.txt]** inside the **[Lab1/Driver]** folder. Be sure to build and run both executables.