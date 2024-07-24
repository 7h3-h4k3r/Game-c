#ifndef USER_DETAILS_H
#define USER_DETAILS_H
#define DATAFILE "user/info.data"
#include "error.h"
struct  User
{
    char name[100];
    int uid;
};
//global variable
struct User player;
int check_uid_is_live(){
    int fd,uid,read_byte;
    struct User entry;
    uid = getuid();
    fd = open(DATAFILE,O_RDONLY);
    if(fd == -1){
        error("cannot open the file");
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