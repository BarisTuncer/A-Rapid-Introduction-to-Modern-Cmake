#include "mylib.h"
#include "csapp.h"
#include "mylib_private.h"
#include <stdio.h>

int lazy_sum(int a, int b) {
  printf("lazy sum takes a nap\n");
  private_helper(2);
  printf("lazy sum is returning\n");
  return a + b;
}

static void private_helper(int a) {
  Sleep(a); // this is from caspp
}
