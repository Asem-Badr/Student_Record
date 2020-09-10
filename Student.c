#include <stdio.h>
#include <string.h>
#include "student.h"
#include "common.h"
int j;
extern data_t student[100];

void student_login(){
    int i;
    char username[50];
    char userpass[10];
    again:printf("Enter UserName :");
    scanf("%s",username);
    printf("Enter Password :");
    scanf("%s",userpass);
   for(i=0;i<100;i++){
    if(strcmp(student[i].name,username)==0 && strcmp(student[i].password,userpass)==0){
        student_screen();
        i=j;
    }else {
        printf("Invalid username or password\n ");
        goto again;
    }

   }
}
void student_screen(){
    char choice;
    loop:printf("\t\t\t\t a.View your record.\t\t\t\t\n\t\t\t\t b.Edit your password.\t\t\t\t\n");
    scanf("%c",&choice);
    switch(choice){
        case 'a' : view_record();
        break;
        case 'b' : edit_password();
        break;
        default: printf("Wrong entry \n");
        goto loop;
        break;
    }
}
void view_record(){
    printf("Name : %s\n Year : %s\n ID : %d\n",student[j].name,student[j].year,student[j].id);

}
void edit_password(){
    char newpassword[10];
    printf("Enter new password : ");
    scanf("%s",newpassword);
    strcpy(student[j].password,newpassword);
}
