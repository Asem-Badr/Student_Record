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
			 printf ("cls");
			 printf ("Enter your password : ");
			 scanf ("%d",&pass);
			 if (pass == admin_pass) {
				 i=1 ;
			 }
			 } while (i==0);
			 admin_interface ();
			 break;
		 }
		 case 2 : {
			 //user interface
			 student_login();
			 break;
		 }
	 }
}

void admin_interface () {
	int choice;
	printf ("1- Add student record\n2- remove student record\n3- Edit student record\n4- View student record\n5- View all records\n6- Edit admin password/n7- back to login\n");
	scanf ("%d",&choice);
	switch (choice){
		case 1 : {
			//Add record fn
			index++;
			add (index);
			break;
		}
		case 2 : {
			//remove record fn
			printf ("enter the selected index : ");
			scanf("%d",&sel_index);
			rmv (sel_index);
			break;
		}
		case 3 : {
			//edit record fn
			printf ("enter the selected index : ");
			scanf("%d",&sel_index);
			edit(sel_index);
			break;
		}
		case 4 : {
			//view record fn
			printf ("enter the selected index : ");
			scanf("%d",&sel_index);
			view (sel_index);
			break;
		}
		case 5 : {
			//view all records fn
			view_all();
			break;
		}
		case 6 : {
			//edit password fn
			edit_admin();
			break;
		}
		case 7 : {
			//login page
			login ();
			break;
		}
	}
}
