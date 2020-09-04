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
}*account_start,*account_current,*account_last;

struct cart_node{
    product *address;
    struct cart_node *next_node;
    int quantity;
}*cart_start,*cart_current,*cart_last;

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
	gotoxy(50,24);
	printf("Product added to Cart....");
	getch();
}

void display_category(int i_index){
    system("cls");
    gotoxy(50,15);
    if(i_index==0){
        printf("------------------MOBILES--------------------");
    }
    else if(i_index==1){
        printf("-----------------LAPTOP-------------------");
    }
    else if(i_index==2){
        printf("----------------FRIDGE----------------");
    }
    else if(i_index==3){
        printf("------------------TV----------------");
    }
    else if(i_index==4){
        printf("---------------PURIFIER--------------------");
    }
    gotoxy(50,16);
    printf("Product ID\tName\t\t\t Price\t\t\n");
  int j,y;
  for(j=0,y=17; j<5; j++,y++){
        gotoxy(50,y);
    printf("%d\t\t%-22s\t %.2f",products[i_index][j].product_id,products[i_index][j].product_name,products[i_index][j].price);
  }
  gotoxy(50,22);
  printf("Enter Product ID to buy or 0 to Go back: ");
  int product_id;
  accept_id: scanf("%d",&product_id);
  if(product_id==0){
    return;
  }
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
     gotoxy(50,22);
    if(lower>=upper){
        printf("\nWrong product ID... Enter correctly: ");
        goto accept_id;
    }
    else{
        printf("\nHow many item: ");
        int quantity;
        scanf("%d",&quantity);
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
    int choice;
    do{
        system("cls");
        gotoxy(61,15);
        printf("---------CATEGORIES----------");
        gotoxy(61,16);
        printf("1.Mobile");
        gotoxy(61,17);
        printf("2.Laptop");
        gotoxy(61,18);
        printf("3.Refrigerator");
        gotoxy(61,19);
        printf("4.TV");
        gotoxy(61,20);
        printf("5.Purifiers");
        gotoxy(61,21);
        printf("6.Back");
        gotoxy(61,22);
        printf("Enter choice: ");
        scanf("%d",&choice);
        if(choice!=6){
           display_category(choice-1);
        }
    }while(choice!=6);
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
	printf("3.EXIT");
	gotoxy(61,20);
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
			account_current=account_start;
			while(account_current!=NULL){
				if(strcmp(username,account_current->username)==0){
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

					if(strcmp(password,account_current->password)==0){
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
				account_current=account_current->address;
			}
			if(account_current==NULL){
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
			account_current=account_start;
            while(account_current!=NULL){
				if(strcmp(username,account_current->username)==0){
                    gotoxy(61,17);
                    printf("Username already taken...");
                    getch();
                    goto acceptusername;
				}
            account_current=account_current->address;
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
        case 3:
            exit(0);
		}
}

void display_cart(){
    //display function
}

void checkout(){
    //display bill.


}

int display_main_menu(){
     do{
         system("cls");
         gotoxy(61,15);
         printf("-------------WELCOME TO ABC SHOPPING-------------");
         gotoxy(61,16);
         printf("1.Shop");
         gotoxy(61,17);
         printf("2.Show cart");
         gotoxy(61,18);
         printf("3.Checkout");
         gotoxy(61,19);
         printf("4.Logout");
         gotoxy(61,20);
         printf("Enter choice: ");
         int choice;
         scanf("%d",&choice);
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
        case 4:
            gotoxy(61,22);
            printf("Logged out....");
            getch();
            return 0;
         }

    }while(1);
}

int main(){
    load_accounts();
	int login_status=0;
	do{
            system("cls");
        while(login_status==0){
		login_status=login();
		system("cls");
        }
        if(login_status==1){
            login_status=display_main_menu();
        }
	}while(1);
	return 0;
}
