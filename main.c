#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include "admin_data.h"

struct account_node{
char username[15];
char password[15];
struct account_node *address;
}*account_start,*current,*account_last;

struct cart_node{
    product *address;
    struct cart_node *next_node;
    int quantity;
}*cart_start,*cart,*cart_last;

void add_to_cart(int *product,int quantity){
    struct cart_node *temp=malloc(sizeof(struct cart_node));
	temp->address=product;
	temp->quantity=quantity;
	temp->next_node=NULL;
	if(cart_start==NULL){
        cart_start=temp;
        cart_last=temp;
	}
	else{
        cart_last->address=temp;
        cart_last=account_last->address;
	}
	printf("Product added to Cart....");
}

void display_category(int i_index){
    printf("Product ID\tName\t\t Price\t\t\n");
  int j;
  for(j=0; j<5; j++){
    printf(" %d\t\t %s\t %d  \t\t %f \t\n",products[i_index][j].product_id,products[i_index][j].product_name,products[i_index][j].price);
  }
  printf("Enter Product ID to buy: ");
  int product_id;
  accept_id: scanf("%d",&product_id);
   //binary search
   int lower=0;
   int upper=5,middle;
    do{
        middle=(upper+lower)/2;
        if(products[i_index][middle].product_id==product_id){
            break;
        }
        else if(products[i_index][middle].product_id<product_id){
            lower=middle+1;
        }
        else if(products[i_index][middle].product_id>product_id){
            upper=middle-1;
        }
    }while(lower<=upper);
    if(lower>=upper){
        printf("\nWrong product ID...");
        goto accept_id;
    }
    else{
        printf("\nHow many item: ");
        int quantity;
        scanf("%d",quantity);
        add_to_cart(&products[i_index][middle],quantity);
    }
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

void shop(){
    printf("---------CATEGORIES----------");
    printf("1.product 1\n");
    printf("2.product 2\n");
    printf("3.product 3\n");
    printf("4.product 4\n");
    printf("5.product 5\n");
    printf("6.Back\n");
    printf("Enter choice: ");
    int choice;
    scanf("%d",&choice);
    if(choice!=6){
       display_category(choice-1);
    }
    return;
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
		    acceptusername: system("cls");
		    gotoxy(61,16);
			printf("\t\tENTER USERNAME: ");
			char username[15];
			fflush(stdin);
			gets(username);
            while(current!=NULL){
				if(strcmp(username,current->username)==0){
                    gotoxy(61,17);
                    printf("Username already taken...");
                    getch();
                    goto acceptusername;
				}
            current=current->address;
			}
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

void show_cart(){
    //display function
}

void check_out(){
    //display bill.

    exit(0);
}

void display_main_menu(){
     do{
         system("cls");
         printf("-------------WELCOME TO ABC SHOPPING-------------");
         gotoxy(61,16);
         printf("1.Shop");
         gotoxy(61,17);
         printf("2.Show cart");
         gotoxy(61,18);
         printf("3.Checkout");
         gotoxy(61,19);
         printf("Enter choice: ");
         int choice;
         scanf("%d",choice);
         switch(choice){
         case 1:
            shop();
            break;
         case 2:
            display_cart();
            break;
         case 3:
            checkout();
            break;
         }

    }while(1);
}

int main(){
    load_accounts();
	int login_status=0;
	while(login_status==0){
		login_status=login();
		system("cls");
	}
	if(login_status==1){
        display_main_menu();
	}
	return 0;
}
