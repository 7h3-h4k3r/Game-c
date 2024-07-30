#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/fcntl.h>
#include "games.h"
int main(){
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
