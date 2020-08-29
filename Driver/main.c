#include <stdio.h>
#include "csapp.h"  
#include "log.h"     // shouldn't be accessible to mylib
int main(){
    printf("Hello master!\n");
    Sleep(3);   // from "csapp.h"
    log_info("Hello from logging!"); // from Log
    log_warn("Are you sure ?"); // from Log
    return 0;
}