#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "admin.h"
char admin_password[50]="12345";
extern data_t student [100];
extern index ;


void add (void)
{
    int flag=0;
    while(flag==0)
    {
        if(student[index].name=='\0')
        {
            flag=1;
            char buffer[100];
            printf("Enter the student name :");
            scanf("%s",&buffer);
            student[index].name=(char*)malloc(strlen(buffer)+1);
            strcpy(student[index].name,buffer);
            printf("\nEnter the student year :");
            scanf("%s",&buffer);
            student[index].year=(char*)malloc(strlen(buffer)+1);
            strcpy(student[index].year,buffer);
            printf("\nEnter the student id :");
            scanf("%d",&student[index].id);

            printf("\nEnter the student password :");
            scanf("%s",&buffer);
            student[index].password=(char*)malloc(strlen(buffer)+1);
            strcpy(student[index].password,buffer);
        }
        else
        {
            index++;
            if (index==100)
                index=0;
        }
    }
}
void rmv (void)
{
    int i;
    int id_user_input;
    view_all();
    printf("Enter the student id : ");
    scanf("%d",&id_user_input);
    for (i=0; i<100; i++)
    {
        if(id_user_input == student[i].id)
        {
            break ;
        }
    }
    student[i].name='\0';
    student[i].year='\0';
    student[i].id=0;
    student[i].password='\0';
}

void edit(void)
{
    char buffer[100];
    int i;
    int user_input;
    char choice;
    view_all();
    printf("Enter the student id : ");
    scanf("%d",&user_input);
    for (i=0; i<100; i++)
    {
        if(user_input == student[i].id)
        {
            break ;
        }
    }
    printf("1-edit name\t2-edit year\t3-edit id\t4-edit password\n");
    scanf("%d",&choice);
    if (choice == 1)
    {
        printf("Enter the student name :");
        scanf("%s",&buffer);
        student[i].name=(char*)malloc(strlen(buffer)+1);
        strcpy(student[i].name,buffer);
    }
    else if(choice ==2)
    {
        printf("\nEnter the student year :");
        scanf("%s",&buffer);
        student[i].year=(char*)malloc(strlen(buffer)+1);
        strcpy(student[i].year,buffer);
    }
    else if (choice ==3)
    {
        printf("\nEnter the student id :");
        scanf("%d",&student[i].id);
    }
    else if (choice ==4)
    {
        printf("\nEnter the student password :");
        scanf("%s",&buffer);
        student[i].password=(char*)malloc(strlen(buffer)+1);
        strcpy(student[i].password,buffer);
    }
    else
    {
        printf("wrong entry");
    }
}
void view (int x)//don't use in main
{
    printf("\n%s\t",student[x].name);
    printf("%s\t\t",student[x].year);
    printf("%d\t\t",student[x].id);
    printf("%s\t",student[x].password);
}
void view_student(void)
{
    system("cls");
    int user_input,i;
    printf("Enter the student id");
    scanf("%d",&user_input);
    for (i=0; i<100; i++)
    {
        if(user_input == student[i].id)
        {
            view(i);
        }
    }

}

void view_all(void)
{
    system("cls");
    int i;
    printf("\nname\t\tyear\t\tid\t\tpassword\n");
    for(i=0; i<100; i++)
    {
        if(student[i].name!='\0')
        {
            view(i);
            printf("\n\n");
        }
    }
}
void edit_admin(void)
{
    printf("Enter the admin's new password");
    scanf("%d",&admin_password);
}
void admin_login(void)
{
    char input_password[50];
    printf("Enter admin's password : ");
    scanf("%s",&input_password);
    while(!(strcmp(admin_password,input_password)==0))
    {
        printf("wrong password\n ");
        printf("Enter Password :");
        scanf("%s",input_password);
    }
    admin_screen();
}
void admin_screen(void)
{
    int choice;
    system("cls");
    printf("Enter the number of the operation you want \n 1-add new student \n 2-remove a student \n 3-edit a student record \n 4-view a record \n 5-view all records \n 6-edit password\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        add();
    }
    else if(choice==2)
    {
        rmv();
    }
    else if(choice==3)
    {
        edit();
    }
    else if(choice==4)
    {
        view_student();
    }
    else if(choice==5)
    {
        view_all();
    }
    else if(choice==6)
    {
        edit_admin();
    }

}
