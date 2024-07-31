#ifndef USER_DETAILS_H
#define USER_DETAILS_H
#define DATAFILE "user/info.data"
#include "error.h"
#include "print_data.h"
int input();
struct  User
{
    char name[100];
    int uid;
    int highscore;
    int credit;
};
//global variable
struct User player;
void high_score(){
    unsigned int top_score = 100;
    struct User entry;
    int fd;
    fd =  open(DATAFILE,O_RDONLY);
    if(fd == -1){
        error("While can't opening the file");
        exit(-1);
    }
    while(read(fd,&entry,sizeof(struct User))){
            if(entry.highscore>top_score){
                top_score = entry.highscore;
                high_score_banner(top_score);
            }
            else{
                printf("You hava a current score in Game \n Name of the gamer: %s",entry.name);
                printf("\nLast score :%d",entry.highscore);
            }
    }
}
int check_uid_is_live(){
    int fd,uid,read_byte;
    struct User entry;
    uid = getuid();
    fd = open(DATAFILE,O_RDONLY);
    if(fd == -1){
        error("cannot open the file");
        return  -1;
    }
    read_byte = read(fd,&entry,sizeof(struct User ));
    while (entry.uid != uid && read_byte >0)
    {   
         read_byte = read(fd,&entry,sizeof(struct User));
   
    }
    close(fd);
    if(read_byte<sizeof(struct User)){
        return -1;
    }else{
        player= entry;
    }
    return 1;
}

void new_register(){
    int fd;
    printf("==========NEW REGISTATION (GAME CLUB)==========\n");
    printf("Enter a player name:\n");
    input();
    player.uid = getuid();
    player.highscore = player.credit = 100;
    fd = open(DATAFILE,O_APPEND|O_WRONLY|O_CREAT , S_IRUSR|S_IWUSR);
    if(fd == -1){
        error("while open a new register file\n");
    }
    if(write(fd,&player,sizeof(struct User))==-1)
        error("While write tha file \n");
    close(fd);
    printf("heyyy buddy welcome the gaming club\n");//make yours
    printf("player name %s\n",player.name);
    printf("player credit %d\n",player.credit);
}
int input(){
    char *name_ptr , input_char;
    name_ptr = player.name;
    do{
        scanf("%c",&input_char);
    }while(input_char == '\n');

    while(input_char != '\n'){
        *name_ptr = input_char;
        scanf("%c",&input_char);
        name_ptr++;
    }
    name_ptr= '\0';
    return 1;

}
#endif