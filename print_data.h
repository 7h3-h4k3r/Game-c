#ifndef PRINT_DATA_H
#define PRINT_DATA_H
#include "user_details.h"
// void banner_one(){
//     printf("Written by");
// }
void banner_two(){
    printf("1.Pick  a correct Number\n2. No Match dealer \n3. Find Ace Game \n4.Show high score \n5.change you name \n 6.Exit the game\n");
    
}
void banner_one(){
  
    // Print the banner
    printf("_________________|      |____________________________________________\n");
    printf("     ,--.    ,--.          ,--.   ,--.\n");
    printf("    |oo  | _  \\  `.       | oo | |  oo|\n");
    printf("o  o|~~  |(_) /   ;       | ~~ | |  ~~|o  o  o  o  o  o  o  o  o  o  o\n");
    printf("    |/\\/\\|   '._,'        |/\\/\\| |/\\/\\|\n");
    printf("__________________        ____________________________________________\n");
    printf("                  |      |Game developed by 7h3-h4k3r\n \t (not for playing must understanding the exploit)");


}


void high_score_banner(int score){
    printf("****************************************\n");
    printf("             High Score %d               \n",score);
    printf("****************************************\n");
}
#endif