#include <stdio.h>
#include <stdlib.h>
#include "system.h"
#include "admin.h"
#include "student.h"
#include "common.h"
extern data_t student [100];
extern char index;
int admin_pass = 123456;
int sel_index;

void login () {
	int person,check,pass,i=0;
	printf ("1- Admin\n2- User\n");
	scanf ("%d",&person);
	 switch (person) {
		 case 1 : {
			 //admin interface
			 do {
			 system("cls");
			 printf ("Enter your password : ");
			 scanf ("%d",&pass);
			 if (pass == admin_pass) {
				 i=1 ;
			 }
			 } while (i==0);
             admin_screen();
			 break;
		 }
		 case 2 : {
			 //user interface
			 student_login();
			 break;
		 }
	 }
}


