#ifndef ERROR_H
#define ERROR_H

void error(char *error_message){
    char prefix_info[100]="ERROR : ";
    strncat(prefix_info,error_message,80);
    printf("%s",prefix_info);
}
#endif