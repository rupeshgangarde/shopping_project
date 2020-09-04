#include <stdio.h>
struct detail
{
  int pid;
  char name[30];
  int price;
  int qty;
};
int main()
{
  struct detail data[6]={{111,"mobiles",15000,7},{222,"laptops",45000,8},{333,"refrigerator",54000,3},{444,"Teleision",58000,2},{555,"Hand mixer",10000,5}
   };
  int i;
  	printf("\t\t\t**-**-HELLO-**-**\n");
  	printf("\n");
  	printf("\t\t\twelcome to our shop\n");
  	printf("\n");
    printf("Product ID\tName\t\t Price\t\t\tquantity\t\t\n");
  for(i=0; i<5; i++)
    {
    printf(" %d\t\t %s\t %d  \t\t %d \t\n", data[i].pid,data[i].name,data[i].price,data[i].qty);
 
    }
  return 0;
}
