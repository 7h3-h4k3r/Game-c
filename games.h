#ifndef GAMES_H
#define GAMES_H
#include "user_details.h"
#include<stdio.h>
#include<stdlib.h>

void jackpot(){
    printf("=+=+=+=+=+=+****JACKPOR.....+=+=+=+=+=+==+\n");
    player.credit +=100;
    printf("you get a 100 credit ");
}
int pick_a_correct_number(){
    int winnner_no,user_no;
    printf("-----------GUESS THE COREECT NUMBER -----------\n");
    printf("\t Each Guess you spend a 10(credit)\n");
    printf("\t you will win the match (you get a 100 credit) *jakpot* \n");
    printf("one and only hind is num start 1 end with 20 (1-20)");
    winnner_no = rand()%20 +1;
    if(player.credit<10){
        printf("your credit is very low &d update your profile\n",player.credit);
    }
    printf("enter your choice : ");
    scanf("%d",&user_no);
    if(winnner_no == user_no){
        jackpot();
    }
    return -1;
    

}
#endif GAMES_H