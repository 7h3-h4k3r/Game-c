#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include "user_details.h"
#include "games.h"
#include "print_data.h"




int main(int argc ,char *argv[]){
    int choice;
    banner_two();
    printf("Enter your choice \n");
    switch (scanf("%d",choice))
    {
    case 1:
        pick_a_correct_number();
        break;
    case 2:
        no_match_dealer();
        break;
    case 3:
        find_ace();
        break;
    default:
        // printf("Invalid choice , Use help comment %s --help or -h",argv[0]);
        printf("Choice is invalide");
        banner_two();
        break;
    }
}


