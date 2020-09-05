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
    product *product_address;
    struct cart_node *next_node;
    int quantity;
    float total;
}*cart_start,*cart_current,*cart_last;

void add_to_cart(int *product,int quantity){
    struct cart_node *temp=malloc(sizeof(struct cart_node));
	temp->product_address=product;
	temp->quantity=quantity;
	temp->next_node=NULL;
	temp->total=(temp->product_address->price)*quantity;
	if(cart_start==NULL){
        cart_start=temp;
        cart_last=temp;
	}
	else{
        //check if product already in cart.
        cart_current=cart_start;
        while(cart_current!=NULL){
            if(temp->product_address->product_id==cart_current->product_address->product_id){
                cart_current->quantity+=quantity;
                cart_current->total+=temp->total;
                free(temp);
                printf("\nProduct added to Cart....Please wait");
                delay(1);
                return;
            }
            cart_current=cart_current->next_node;
        }
        cart_last->next_node=temp;
        cart_last=cart_last->next_node;
	}
	printf("\nProduct added to Cart....Please wait");
	delay(1);
}

void display_category(int i_index){
    start:
    system("cls");
    printf("\n");
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
    printf("\nProduct ID\tName\t\t\t Price\t\t\n");
  int j;
  for(j=0; j<5; j++){
    printf("\n%d\t\t%-22s\t %.2f",products[i_index][j].product_id,products[i_index][j].product_name,products[i_index][j].price);
  }
  printf("\nEnter Product ID to buy or 0 to Go back: ");
  int product_id;
  scanf("%d",&product_id);
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
    if(lower>upper){
        printf("\nWrong product ID... Please wait");
        delay(1);
        goto start;
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
        printf("---------CATEGORIES----------\n");
        printf("1.Mobile\n");
        printf("2.Laptop\n");
        printf("3.Refrigerator\n");
        printf("4.TV\n");
        printf("5.Purifiers\n");
        printf("6.Back\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        if(choice!=6){
           display_category(choice-1);
        }
    }while(choice!=6);
    return;
}


int login(){
	printf("-------------WELCOME TO ABC SHOPPING-------------\n");
	printf("Please Login or Create a new account: \n\n");
	printf("1.Login\n");
	printf("2.New Account\n");
	printf("3.EXIT\n");
	printf("Enter Choice: ");
	int choice;
	scanf("%d",&choice);
	switch(choice){
		case 1:{
		    system("cls");
		    printf("-------------WELCOME TO ABC SHOPPING-------------\n");
		    printf("\tUSERNAME: ");
			char username[15];
			fflush(stdin);
			gets(username);
			account_current=account_start;
			while(account_current!=NULL){
				if(strcmp(username,account_current->username)==0){
					printf("\n\tPASSWORD: ");
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
						printf("\n\tLogin Successful");
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
				printf("\nNO ACCOUNT FOUND...Please wait");
				delay(1);
			}
			return 0;
		}
		case 2:{
		    acceptusername: system("cls");
		    printf("\n\tENTER USERNAME: ");
			char username[15];
			fflush(stdin);
			gets(username);
			account_current=account_start;
            while(account_current!=NULL){
				if(strcmp(username,account_current->username)==0){
                    printf("\nUsername already taken...Please wait");
                    delay(1);
                    goto acceptusername;
				}
            account_current=account_current->address;
			}
			printf("\n\tENTER PASSWORD: ");
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
			printf("\nAccount Created....Please wait to Continue to Login.");
			delay(1);
			return 0;
            }
        case 3:
            exit(0);
		}
}


int display_cart(){
	if(cart_start==NULL){
		printf("\nCart is Empty");
		delay(1);
	}
	else
	{
	    system("cls");
	    printf("\n----------------------CART----------------------------");
	    printf("\nProduct ID\tName\t\t\t Price\t\t QUANTITY\n");
		cart_current=cart_start;
		while(cart_current!=NULL)
		{
			printf("\n%d\t\t%-22s\t %.2f\t %d\n",cart_current->product_address->product_id,cart_current->product_address->product_name,
            cart_current->product_address->price,cart_current->quantity);
			cart_current=cart_current->next_node;

		}
	}
	getch();
	return;
}


void check_out(){
    int grand_total=0;
    system("cls");
    if(cart_start==NULL)
	{
		printf("\nCart is Empty");
	}
	else
	{
	    printf("--------------------CHECK---------------------\n");
	     printf("\nProduct ID\tName\t\t  QUANTITY\tTOTAL\n");
		cart_current=cart_start;
		while(cart_current!=NULL)
		{
			printf("%d\t\t%-22s\t %d\t %.2f\n",cart_current->product_address->product_id,cart_current->product_address->product_name,
            cart_current->quantity,cart_current->total);
            grand_total+=cart_current->total;
			cart_current=cart_current->next_node;
		}
		printf("-----------------------------------------------------\n");
		printf("\t\t\t\t\tGRAND TOTAL = %d",grand_total);
	}
	printf("\n-------------THANK YOU FOR SHOPPING WITH US...-----------");

	cart_current=cart_start;
	while(cart_current!=NULL){
        struct cart_node *pointer=cart_current->next_node;
        free(cart_current);
        cart_current=pointer;
	}
	cart_start=NULL;
	getch();
}



int display_main_menu(){
     do{
         system("cls");
         printf("-------------WELCOME TO ABC SHOPPING-------------\n");
         printf("1.Shop\n");
         printf("2.Show cart\n");
         printf("3.Checkout\n");
         printf("4.Logout\n");
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
            check_out();
            break;
        case 4:
            if(cart_start!=NULL){
                printf("\nCart not empty....Logging out will empty the cart...\n");
                printf("Do you want to Logout(y/n): ");
                fflush(stdin);
                char choice;
                scanf("%c",&choice);
                if(choice=='y' || choice=='Y'){
                    cart_current=cart_start;
                    while(cart_current!=NULL){
                        struct cart_node *pointer=cart_current->next_node;
                        free(cart_current);
                        cart_current=pointer;
                    }
                    cart_start=NULL;
                    printf("\nLogged out....Please wait");
                    delay(1);
                    return 0;
                }
                else
                    break;
            }
            printf("\nLogged out....Please wait");
            delay(1);
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
