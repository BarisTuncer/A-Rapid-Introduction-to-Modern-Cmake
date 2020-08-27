#include "csapp.h"
#include "mylib_private.h"
#include "mylib.h"
#include <stdio.h>
// #include "log.h"  // should not be possible unless mylib links it!
void secret_helper_for_fantastic_sum(int a){
    Sleep(a); // this is from caspp
}

int fantastic_sum(int a , int b){
    printf("fantastic sum is sleeping via secret implementation via Sleep in  csapp\n");
    secret_helper_for_fantastic_sum(3);
    printf("fantastic sum is returning\n");
    return a+b;
}