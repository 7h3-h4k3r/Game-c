#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include "user_details.h"



int main(){
    if(check_uid_is_live() == -1){
        new_register();
    }
}


