#include <stdio.h>
#include "csapp.h"  
#include "log.h"    
int main(){
    printf("Hello Lab2\n");
    Sleep(3);   // from "csapp.h"
    log_info("Hello from logging!"); // from log
    log_warn("Are you sure ?");
    return 0;
}