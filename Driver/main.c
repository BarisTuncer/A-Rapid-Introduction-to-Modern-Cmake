
// #include "csapp.h" // will create an error unless linking in
#include "log.h"
#include "mylib.h"
// #include "mylib_private.h" //-- > will give an error whether linking in
#include <stdio.h>

int main() {
  printf("Hello csapp!\n");
  int i = lazy_sum(3, 5);
  // Sleep(3);          // from "csapp.h"
  // private_helper(i); // from "mylib_private.h"s
  printf("Sum is %d\n", i);
  log_info("Hello from logging!");
  log_warn("Are you sure that the value of i should be %d", i);
  return 0;
}