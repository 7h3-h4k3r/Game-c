#ifndef GAMES_H
#define GAMES_H
#include "user_details.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void print_cards(const char *message,const char *cards,int picks){
    printf("\n\t***** %s *****\n",message);
    printf(" \n\t._.\t._.\t._.\n");
    printf(" \t|%c|\t|%c|\t|%c|\n",cards[0],cards[1],cards[2]);
    if(picks == -1){
        printf("\t 1 \t 2 \t 3");
    }else{
        for(int i=0;i<picks;i++){
            printf(" \t\t");
        }
        printf("\t\t\t\t %d <---your pick",picks+1);
    }
}
int wager_fun(int avilable_credit ){
    int wager,total_wager;
    printf("How many credit do you wager Avilable credit in you account %d \n",player.credit);
    scanf("%d",&wager);
    if(wager<1){
        printf("Nice try Dont't waste you time keep put vaild Amount\n");
        return -1;
    }
    if(wager>avilable_credit){
        printf("if you wager more than your credit , so' you can't play the game(update your credit)\n");
        exit(-1);
    }
    return wager;
}
int find_ace(){
    srand(time(0));
    int wager_one =-1, pick =-1,choice_one = 1,choice_two;
    int ace,i,wager_two =-1;
    ace = rand()%3;
    player.credit = 100;
    char cards[3]= {'x','x','x'};
    if(player.credit==0){
        printf("you can't have a credit Please update your credit\n");
        return -1;
    }
    if(wager_one == -1){
        wager_one= wager_fun(player.credit);
    }

    print_cards("Credit's deal",cards,pick);
    
    if((pick>1)||(pick<3)){
        printf("\nSelect 1 , 2 , or 3\n");
        scanf("%d",&pick);
    }
    pick --;
    i = 0;
    while(i==ace || i == pick){
        i++;
    }
    cards[i]='Q';
    print_cards("Reveal Queen",cards,pick);
    while(choice_one){
        printf("\nWould you like to: [C] is  change your pick or  [i] is increase your wager \n");
        while ((choice_two = getchar()) =='\n');
        
            if(choice_two == 'i'){

                choice_one = 0;
                if(wager_two == -1){
                    wager_two = wager_fun(player.credit);
                }
            }else if (choice_two == 'c')
            {
                i =0;
                while (i == pick||cards[i]=='Q')
                    i++;
                pick = i;
                printf("Your cards pick has been changed %d",pick+1);
            }
    }
    for(i =0;i<3;i++){
        if(ace == i){
            cards[i] = 'A';
        }else{
            cards[i] = 'Q';
        }
    }
    print_cards("End Result",cards,pick);
    if (pick == ace) { // Handle win.
        printf("\nYou have won %d credits from your first wager\n", wager_one);
        player.credit += wager_one;
        if (wager_two != -1) {
            printf("\nand an additional %d credits from your second wager!\n", wager_two);
            player.credit += wager_two;
        }
    } else { // Handle loss.
        printf("\nYou have lost %d credits from your first wager\n", wager_one);
        player.credit-= wager_one;
        if (wager_two != -1) {
            printf("\nand an additional %d credits from your second wager!\n", wager_two);
            player.credit -= wager_two;
        }
    }
    return 0;
}  
int no_match_dealer(){
    int wager = -1,number[16],j,match = -1;
    srand((time(0)));
    printf("=============NO MATCH DEALER===========\n");
    printf("In this game , you can wager up to all of your credit's\n");
    printf("The dealer will cost deal out 16 random number between 0 to 99.\n");
    printf("If there are No match among them , you double your Money\n");

    if(player.credit == 0){
        printf("Your credit is zero , so' you cannot play the game(update your credit)\n");
        return -1;
    }
    if(wager == -1){
        wager = wager_fun(player.credit);
    }
    printf("::::::::: Dealing out 16 Random number :::::::::");
    for(int i=0;i<16;i++){
        number[i] = rand() % 100;
        printf("%d\t",number[i]);
        if(i%8 == 7){
            printf("\n");
        }
    }
    for(int i=0;i<16;i++){
        j = i+1;
        while (j<16)
        {
            if(number[i] == number[j]){
                match = number[i];
            }
            j++;
        }
    }
    if(match ==- 1){
        printf("There were no Match the number %d !\n",match);
        player.credit +=wager;
    }else{
        printf("The dealer matched the number %d ",match);
        printf("your Lost %d credit",player.credit);
        player.credit -=wager;
    }
    return 0;
}
void jackpot(){
    printf("\t\t=+=+=+=+=+=+****JACKPOR.....+=+=+=+=+=+==+\n");
    player.credit +=100;
    printf("you get a 100 credit ");
}
int pick_a_correct_number(){
    int winnner_no,user_no;
    srand(time(0));
    printf("\n-----------GUESS THE COREECT NUMBER -----------\n");
    printf("\t Each Guess you spend a 10(credit)\n");
    printf("\t you will win the match (you get a 100 credit) *jakpot* \n");
    printf("one and only hind is num start 1 end with 20 (1-20)");
    winnner_no = rand()%20 +1;
    if(player.credit<10){
        printf("your credit is very low %d update your profile\n",player.credit);
    }
    printf("enter your choice : ");
    scanf("%d",&user_no);
    printf("Rand number is %d\n",winnner_no);
    if(winnner_no == user_no){
        jackpot();
    }
    return -1;
}
#endif //GAMES_H