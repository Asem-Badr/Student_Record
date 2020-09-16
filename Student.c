#include <stdio.h>
#include <string.h>
#include "student.h"
#include "common.h"
#include <conio.h>
int check_flag;
int i = 0 ;
extern data_t student[100];
extern char index ;
void student_login()
{
    system("cls");
    char username[50];
    char userpass[10];
    printf("Enter UserName :");
    scanf("%s",username);
    printf("Enter Password :");
    scanf("%s",userpass);
    for(i=0; i<(index+1); i++)
    {
        if((strcmp(student[i].name,username)==0) && (strcmp(student[i].password,userpass)==0))
        {
            student_screen();
            check_flag = 1 ;
        }
    }
    if(check_flag == 0){
        i=0;
        student_login();
    }

}

void student_screen()
{
    system("cls");
    int choice;
    printf("\t\t\t\t 1.View your record.\t\t\t\t\n\t\t\t\t 2.Edit your password.\t\t\t\t\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        view_record();
    }
    else if(choice==2)
    {
        edit_password();
    }

}
void view_record()
{
    system("cls");
    printf("Name : %s\n Year : %s\n ID : %d\n",student[i].name,student[i].year,student[i].id);

}
void edit_password()
{
    char buffer[100];
    printf("Enter new password : ");
    scanf("%s",&buffer);
    student[i].password=(char*)malloc(strlen(buffer)+1);
    strcpy(student[i].password,buffer);
}
