#include<stdio.h>
#include<string.h>
#include"student.h"
#include"common.h"
int j;
 struct data student[100];
void student_data(){
   student[1].name="Mohmed Ahmed";
   student[1].id=129789;
   student[1].year="2nd";
   student[1].password="12345";
   student[2].name="Mohmed Ali";
   student[2].id=128789;
   student[2].year="2nd";
   student[2].password="123456";
   student[3].name="Assem Moustafa";
   student[3].id=128787;
   student[3].year="2nd";
   student[3].password="1234567";
   student[4].name="Assem ali";
   student[4].id=128767;
   student[4].year="2nd";
   student[4].password="123456789";
   student[5].name="Ahmed Moustafa";
   student[5].id=268691;
   student[5].year="2nd";
   student[5].password="2234567";
   student[6].name="Abdelrahman Moustafa";
   student[6].id=128798;
   student[6].year="2nd";
   student[6].password="1234567";
   student[7].name="Ahmed Ali";
   student[7].id=126987;
   student[7].year="2nd";
   student[7].password="1234567";
   student[8].name="Abdelrahman Abobakr";
   student[8].id=328787;
   student[8].year="2nd";
   student[8].password="1234567";
   student[9].name="Assem Mossad";
   student[9].id=428787;
   student[9].year="2nd";
   student[9].password="1234567";
   student[10].name="Abdelrahman Elshahat";
   student[10].id=1111111;
   student[10].year="2nd";
   student[10].password="1234567";


}
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
