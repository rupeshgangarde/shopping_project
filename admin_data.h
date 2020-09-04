
typedef struct product{
  int product_id;
  char product_name[30];
  float price;
} product;


const product products[5][5]={
//mobile
{{1111," Apple Iphone 7",29000},{1112,"redmi note 9",20000},{1113,"samsang M31",19000},{1114,"poco F20",25000},{1115,"realme X5",15000}},
//laptop
{{1116,"HP",59000},{1117,"Dell",47000},{1118,"Apple",98000},{1119,"Lenovo",22000},{1120,"Asus",28000}},
//Refrigerators
{{1121,"LG",12000},{1122,"Godrej",22000},{1123,"Samsung",19000},{1124,"Whirlpool",25000},{1125,"Panasonic",24000}},
//televisions
{{1126,"Panasonic",57000},{1127,"Sony",71000},{1128,"Micromax",45000},{1129,"Philips",38000},{1130,"Mi TV",47000}},
//water purifier
{{1131,"Kent UF water purifier",2100},{1132,"Sure UF water purifier",4700},{1133,"Pureit water purifier",5100},{1134,"Eureka Forbes",4000},{1135,"Blue Star",3300}},
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



