#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "admin.h"
int admin_password;
extern data_t student [100];
void add (int arr_index)
{
    char buffer[100];
    printf("Enter the student name :");
    scanf("%s",&buffer);
    student[arr_index].name=(char*)malloc(strlen(buffer)+1);
    strcpy(student[arr_index].name,buffer);
    printf("\nEnter the student year :");
    scanf("%s",&buffer);
    student[arr_index].year=(char*)malloc(strlen(buffer)+1);
    strcpy(student[arr_index].year,buffer);
    printf("\nEnter the student id :");
    scanf("%d",&student[arr_index].id);

    printf("\nEnter the student password :");
    scanf("%s",&buffer);
    student[arr_index].password=(char*)malloc(strlen(buffer)+1);
    strcpy(student[arr_index].password,buffer);
}
void rmv (int arr_index)
{
    student[arr_index].name='\0';
    student[arr_index].year='\0';
    student[arr_index].id=0;
    student[arr_index].password='\0';
}

void edit(int arr_index)
{
    printf("Enter the new student data :\n");
     add( arr_index);
}
void view (int arr_index)
{
    printf("\nthe student name :%s\n",student[arr_index].name);
    printf("the student year :%s\n",student[arr_index].year);
    printf("the student id :%d\n",student[arr_index].id);
    printf("the student password :%s\n",student[arr_index].password);
}

void view_all(void)
{
    int i;
    for(i=0;i<100;i++)
    {
        if(student[i].name!='\0')
        {
            view(i);
            printf("\n*****************************************\n");
        }
    }
}
void edit_admin(void)
{
    printf("Enter the admin's new password");
    scanf("%d",&admin_password);
}



