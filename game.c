#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include "user_details.h"
#include "games.h"



int main(){
    if(check_uid_is_live() == -1){
        new_register();
    }
   printf(" (move  a update  a while) pick the number game is live ");
   if(pick_a_correct_number() == -1){
    printf("lost -10 from your credit\n");
   }

}


