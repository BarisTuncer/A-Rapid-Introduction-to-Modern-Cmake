
#include "log.h" // shouldn't be accessible to mylib
#include "mylib.h"
#include <stdio.h>
// #include "csapp.h" // will create an error unless linking in
// #include "mylib_private.h" //-- > will give an error whether linking in

int main() {
  printf("Hello csapp!\n");
  // Sleep(3); // from "csapp.h"
  int i = lazy_sum(3, 5);
  // secret_helper_for_fantastic_sum(int); // from "mylib_private.h"
  printf("Sum is %d\n", i);
  log_info("Hello from logging!");
  log_warn("Are you sure that the value of i should be %d", i);
  return 0;
}