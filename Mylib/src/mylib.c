#include "mylib.h"
#include "csapp.h"
#include "mylib_private.h"
#include <stdio.h>
// #include "log.h"  // should not be possible unless mylib links it!
void mylibs_secret_helper(int a) {
  Sleep(a); // this is from caspp
}

int lazy_sum(int a, int b) {
  printf("lazy sum takes a nap\n");
  mylibs_secret_helper(3);
  printf("fantastic sum is returning\n");
  return a + b;
}