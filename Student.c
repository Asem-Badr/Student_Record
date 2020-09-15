#include <stdio.h>
#include <string.h>
#include "student.h"
#include "common.h"
int i;
int j;

extern data_t student[100];

void student_login()
{
    system("cls");

    char username[50];
    char userpass[10];
    printf("Enter UserName :");
    scanf("%s",username);
    printf("Enter Password :");
    scanf("%s",userpass);
    for(i=0; i<100; i++)
    {

        i=j;
        student_screen();
        break;

    }
    while(!(strcmp(student[i].name,username)==0 && strcmp(student[i].password,userpass)==0))
    {
        printf("Invalid username or password\n ");
        printf("Enter UserName :");
        scanf("%s",username);
        printf("Enter Password :");
        scanf("%s",userpass);
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
    printf("Name : %s\n Year : %s\n ID : %d\n",student[j].name,student[j].year,student[j].id);

}
void edit_password()
{
    char buffer[100];
    printf("Enter new password : ");
    scanf("%s",&buffer);
    student[j].password=(char*)malloc(strlen(buffer)+1);
    strcpy(student[j].password,buffer);
}
