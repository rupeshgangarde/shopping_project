#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h>

struct account_node{
char username[15];
char password[15];
struct account_node *address;
}*account_start,*current,*account_last;

void gotoxy(int x,int y){
	COORD crd;
	crd.X=x;
	crd.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),crd);
}

void delay(int second){
	clock_t start=clock();
		while(clock()<start+(second*1000));
}

void newaccount(char user[],char pass[]){
	struct account_node *temp=malloc(sizeof(struct account_node));
	strcpy(temp->username,user);
	strcpy(temp->password,pass);
	temp->address=NULL;
	if(account_start==NULL){
        account_start=temp;
        account_last=temp;
	}
	else{
        account_last->address=temp;
        account_last=account_last->address;
	}
}

int login(){
	gotoxy(61,15);
	printf("-------------WELCOME TO ABC SHOPPING-------------");
	gotoxy(61,16);
	printf("\tPlease Login or Create a new account: \n");
	gotoxy(61,17);
	printf("1.Login");
	gotoxy(61,18);
	printf("2.New Account");
	gotoxy(61,19);
	printf("Enter Choice: ");
	int choice;
	scanf("%d",&choice);
	switch(choice){
		case 1:{
		    system("cls");
		    gotoxy(61,15);
            printf("-------------WELCOME TO ABC SHOPPING-------------");
		    gotoxy(61,16);
			printf("\t\tUSERNAME: ");
			char username[15];
			fflush(stdin);
			gets(username);
			current=account_start;
			while(current!=NULL){
				if(strcmp(username,current->username)==0){
					gotoxy(61,18);
					printf("\t\tPASSWORD: ");
					char password[15];
					int j=0;
					do{
						password[j]=getch();
						if(password[j]!='\r'){
							printf("*");
						}
						j++;
					}while(password[j-1]!='\r');
					password[j-1]='\0';

					if(strcmp(password,current->password)==0){
						gotoxy(61,19);
						printf("\t\tLogin Successful");
						j=0;
						while(j<3){
							delay(1);
							printf(".");
							j++;
						}
					}
					return 1;
				}
				current=current->address;
			}
			if(current==NULL){
				gotoxy(61,18);
				printf("NO ACCOUNT FOUND...");
				getch();
			}
			return 0;
		}
		case 2:{
		    system("cls");
		    gotoxy(61,16);
			printf("\t\tENTER USERNAME: ");
			char username[15];
			fflush(stdin);
			gets(username);
			//search if same username exist.
			gotoxy(61,17);
			printf("\t\tENTER PASSWORD: ");
			char password[15];
			int j=0;
			do{
				password[j]=getch();
				if(password[j]!='\r'){
					printf("*");
				}
				j++;
			}while(password[j-1]!='\r');
			password[j-1]='\0';
			newaccount(username,password);
			gotoxy(61,18);
			printf("Account Created.... Continue to Login.");
			getch();
			return 0;
		}
	}
}

int main(){
    //admin data
    newaccount("ligdevaidehi","12345");
    newaccount("rupeshgangarde","12345");
	int login_status=0;
	while(login_status==0){
		login_status=login();
		system("cls");
	}
	if(login_status==1){
	}

	return 0;
}
