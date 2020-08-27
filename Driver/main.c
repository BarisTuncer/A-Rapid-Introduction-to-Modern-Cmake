#include <stdio.h>
#include "log.h"
int main(){
    printf("Wellcome to Step2!\n");
    log_info("Hello from logging!");
    int i = 5;
    log_warn("Are you sure that the value of i should be %d",i);
    return 0;
}