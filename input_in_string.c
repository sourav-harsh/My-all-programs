#include<stdio.h>

int main(){
    char *name[50];
    printf("Enter your name\n");
     gets(name);
    printf("Your name is %s\n",name);
    return 0;
}