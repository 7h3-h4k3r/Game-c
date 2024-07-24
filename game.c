#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include "user_details.h"



int main(){
    if(input() == 1){
        printf("Name has been stored {%s}",player.name);
    }
    if(check_uid_is_live() == -1){
        printf("cannot find it ");
    }
}


