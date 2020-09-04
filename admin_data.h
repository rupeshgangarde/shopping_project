
typedef struct product{
  int product_id;
  char product_name[30];
  float price;
} product;


const product products[5][5]={
//Cmobile
{{id,"name",price},{id,"name",price},{id,"name",price},{id,"name",price},{id,"name",price}},
//Category 2
{{id,"name",price},{id,"name",price},{id,"name",price},{id,"name",price},{id,"name",price}},
//Category 3
{{id,"name",price},{id,"name",price},{id,"name",price},{id,"name",price},{id,"name",price}},
//Category 4
{{id,"name",price},{id,"name",price},{id,"name",price},{id,"name",price},{id,"name",price}},
//Category 5
{{id,"name",price},{id,"name",price},{id,"name",price},{id,"name",price},{id,"name",price}},
};

void load_accounts(){
    newaccount("rupeshgangarde","12345");
    newaccount("vaidehiligde","12345");
}

void delay(int second){
	clock_t start=clock();
		while(clock()<start+(second*1000));
}


void gotoxy(int x,int y){
	COORD crd;
	crd.X=x;
	crd.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),crd);
}



