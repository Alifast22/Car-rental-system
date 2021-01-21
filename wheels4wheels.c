
#include<string.h>
#include <stdlib.h>
#include <time.h>
#include<stdio.h>
#include<unistd.h>
#include<windows.h>
#include <conio.h>
int main();
int CID;
struct User
{
	int ID;
	char username[20];
	char useremail[200];
	char password[20];
	char bookingmode[20];
	char time[200];
	char preference[200];
	int amountpaid;
	int cancel;
	int CID;
};
struct co_info{
    int flag;
 	int ID;
	char carname[100];
	char cname[100];
	char add[100];
	char purpose[200];
	int mnum;
	char pnum[11];
	int d;
	int m;
	int y; 
	int de;
	int me;
	int ye;
	int seats;
	int price;
	int rcount;
	float review;
    int CID;
};

void sortlowtohigh(int  data[],int size){
	int i,j,temp;
	 for (i =0; i < size; ++i) 
        {
 
            for (j = i + 1; j < size; ++j)
            {
 
                if (data[i] > data[j]) 
                {
 
                    temp =  data[i];
                    data[i] = data[j];
                    data[j] = temp;
 
                }
 
            }
 
}
}
void sorthightolow(int data[],int size){

	int i,j,temp;
	 for (i =0; i < size; ++i) 
        {
 
            for (j = i + 1; j < size; ++j)
            {
 
                if (data[i] < data[j]) 
                {
 
                    temp =  data[i];
                    data[i] = data[j];
                    data[j] = temp;
 
                }
 
            }
 
}
}
void reviewhightolow(float data[],int size){

	int i,j;
	float temp;
	 for (i =0; i < size; ++i) 
        {
 
            for (j = i + 1; j < size; ++j)
            {
 
                if (data[i] < data[j]) 
                {
 
                    temp =  data[i];
                    data[i] = data[j];
                    data[j] = temp;
 
                }
 
            }
 
}
}
void removeduplicate(int arr[],int size){
	int i,j,k;
	for(i=0; i<size; i++)
    {
        for(j=i+1; j<size; j++)
        {
            /* If any duplicate found */
            if(arr[i] == arr[j])
            {
                /* Delete the current duplicate element */
                for(k=j; k<size; k++)
                {
                    arr[k] = arr[k + 1];
                }

                /* Decrement size after removing duplicate element */
                size--;

                /* If shifting of elements occur then don't increment j */
                j--;
            }
        }
    }
}
void reviewremoveduplicate(float arr[],int size){
	int i,j,k;
	for(i=0; i<size; i++)
    {
        for(j=i+1; j<size; j++)
        {
            /* If any duplicate found */
            if(arr[i] == arr[j])
            {
                /* Delete the current duplicate element */
                for(k=j; k<size; k++)
                {
                    arr[k] = arr[k + 1];
                }

                /* Decrement size after removing duplicate element */
                size--;

                /* If shifting of elements occur then don't increment j */
                j--;
            }
        }
    }
}
int printstation(struct co_info car)
{
int flag=0;	
printf("CarID: %d ",car.CID);
printf("CarName: %s\t ",car.carname);
printf("Car Type:%s\t",car.purpose);
printf("Model Year: %d\t ",car.mnum);
printf("Seating Capacity: %d\t ",car.seats);
printf("PricePerDay: %d\t ",car.price);
printf("Reviews: %f\n",car.review);
flag++;
return flag;
}
NameQuery(char choice[])
{
  FILE *fp;
    fp=fopen("owner.bin","rb");
    int x=0;
    struct co_info car;
	char pref[100];
	int i,flag;
	printf("Write car name you prefer: ");
	fflush(stdin);
	gets(pref);
	system("cls");
	char input[10];
	strcpy(input,"Wedding");
	while(fread(&car,sizeof(struct co_info),1,fp))
	{
		if(strcmp(pref,car.carname)==0&&strcmp(choice,car.purpose)==0&&car.flag==0)
		{
	     x=printstation(car);	
	     }
	
	}

fclose(fp);
if(x==0)
	{
	 printf("No cars found,Returning to mainscreen.......");
	 sleep(2);
	 main();
	}
}
ModelQuery(char choice[])
{
 struct co_info car;
      FILE *fp;
      fp=fopen("owner.bin","rb");
	  int i,x=0,mod;
      printf("Enter desired model year? ");
      scanf("%d",&mod);
      system("cls");
      while(fread(&car,sizeof(struct co_info),1,fp))
      {
		  
       if(mod==car.mnum&&strcmp(choice,car.purpose)==0&&car.flag==0)
       {   
        x=printstation(car);
        }    
	  }
	if(x==0)
	{
	 printf("No cars found,Returning to mainscreen.......");
	 sleep(2);
	 main();
	}
	  
}
SeatingQuery(char choice[])
{
	int mod;
    FILE *fp;
	struct co_info car;
    fp=fopen("owner.bin","rb");
	printf("Write number of seats  you prefer: ");
   	  scanf("%d",&mod);
   	  system("cls");
   	  int x=0;
   	  while(fread(&car,sizeof(struct co_info),1,fp))
   	  {
   	  	if(mod==car.seats&&strcmp(choice,car.purpose)==0&&car.flag==0)
   	  	{
   	  	x=printstation(car);
		 }
	
}
if(x==0)
	{
	 printf("No cars found,Returning to mainscreen.......");
	 sleep(2);
	 main();
	}
}
void NameBrowse(char choice[])
{
    int x=0;
    FILE *fp;
	struct co_info car;
    fp=fopen("owner.bin","rb");
   	system("cls");
   	while(fread(&car,sizeof(struct co_info),1,fp))
   	  {
   	  	if(strcmp(car.purpose,choice)==0&&car.flag==0)
   	  	{
   	  	x=printstation(car);
		 }
	

}
if(x==0)
	{
	 printf("No cars found,Returning to mainscreen.......");
	 sleep(2);
	 main();
	}
}
void Modelbrowseearliesttorecent(char choice[])
{
 FILE* ptr;
ptr=fopen("owner.bin","rb");
   struct co_info read;
	int count=0;
	while(fread(&read,sizeof(struct co_info),1,ptr)){
		if(strcmp(choice,read.purpose)==0&&read.flag==0)
			count++;
	}
	int sorted[count];
	 int i=0;
	 while(fread(&read,sizeof(struct co_info),1,ptr)){
		if(strcmp(choice,read.purpose)==0&&read.flag==0)
			{
			 sorted[i]=read.mnum;
			 i++;
			}
	
	}
	 i=0;
	 sortlowtohigh(sorted,count);
	 removeduplicate(sorted,count);
	 fseek(ptr,0,SEEK_SET);
	 int x=0;
	 int j;
	for (j=0;j<count;j++)
	{
	while(fread(&read,sizeof(struct co_info),1,ptr)){
			if(sorted[i]==read.mnum&&strcmp(choice,read.purpose)==0&&read.flag==0){
			x=printstation(read);
			}

			
	}
	fseek(ptr,0,SEEK_SET);
	i++;
	}
	if(x==0)
	{
	 printf("No cars found,Returning to mainscreen.......");
	 sleep(2);
	 main();
	}
}
void Modelbrowserecenttoearliest(char choice[])
{
 FILE* ptr;
	ptr=fopen("owner.bin","rb");
	struct co_info read;
	int count=0;
	while(fread(&read,sizeof(struct co_info),1,ptr)){
		if(strcmp(choice,read.purpose)==0&&read.flag==0)
			count++;
	}
	fseek(ptr,0,SEEK_SET);
	int c=0;
	int sorted[count];
		while(fread(&read,sizeof(struct co_info),1,ptr))
		{
		  
		  if(strcmp(choice,read.purpose)==0&&read.flag==0)
		   {
			sorted[c]=read.mnum;
			c++;
		    }
	  }
	  int x;
	int i=0;
	 sorthightolow(sorted,count);
	 removeduplicate(sorted,count);
	 fseek(ptr,0,SEEK_SET);
	 int j;
	for (j=0;j<count;j++){
	while(fread(&read,sizeof(struct co_info),1,ptr)){
			if(sorted[i]==read.mnum&&strcmp(choice,read.purpose)==0&&read.flag==0){
			x=printstation(read);
			}

			
	}
	fseek(ptr,0,SEEK_SET);
	i++;
	}
	if(x==0){
		printf("No car Found\nreturning to main menu");
		sleep(2);
		main();
	}
	  
}
void SeatingcapacityLowesttoHighest(char choice[])
{
 	FILE* ptr;
	ptr=fopen("owner.bin","rb");
	struct co_info read;
	int count=0;
	while(fread(&read,sizeof(struct co_info),1,ptr)){
		if(strcmp(read.purpose,choice)==0&&read.flag==0)
			count++;
	}
	int sorted[count];
	fseek(ptr,0,SEEK_SET);
	int c=0;
	while(fread(&read,sizeof(struct co_info),1,ptr)){
	  if(strcmp(read.purpose,choice)==0&&read.flag==0)
	   {
	   sorted[c]=read.seats;
	   c++;
       }
	}
	
	int i=0,x=0;
	 sortlowtohigh(sorted,count);
	 removeduplicate(sorted,count);
	 fseek(ptr,0,SEEK_SET);
	 int j;
	for (j=0;j<count;j++){
	while(fread(&read,sizeof(struct co_info),1,ptr)){
			if(sorted[i]==read.seats&&strcmp(read.purpose,choice)==0&&read.flag==0)
			{
			printf("CarID: %d\t ",read.CID);
            printf("CarName: %s\t ",read.carname);
            printf("Model Year: %d\t ",read.mnum);
            printf("Seating Capacity: %d\t ",read.seats);
            printf("PricePerDay: %d\t ",read.price);
            printf("Reviews: %f\n",read.review);
			x++;	
			}

			
	}
	fseek(ptr,0,SEEK_SET);
	i++;
	}
	if(x==0)
	{
	 printf("No cars found,Returning to mainscreen.......");
	 sleep(2);
	 main();
	}
}
void Seatingcapacityhighesttolowest(char choice[])
{
 FILE* ptr;
	ptr=fopen("owner.bin","rb");
	struct co_info read;
	int count=0;
	while(fread(&read,sizeof(struct co_info),1,ptr)){
		if(strcmp(choice,read.purpose)==0&&read.flag==0)
			count++;
	}
	fseek(ptr,0,SEEK_SET);
	int c=0;
	int sorted[count];
		while(fread(&read,sizeof(struct co_info),1,ptr))
		{
		  
		  if(strcmp(choice,read.purpose)==0&&read.flag==0)
		   {
			sorted[c]=read.seats;
			c++;
		    }
	  }
	int i=0,x=0;
	 sorthightolow(sorted,count);
	 removeduplicate(sorted,count);
	 fseek(ptr,0,SEEK_SET);
	 int j;
	for (j=0;j<count;j++){
	while(fread(&read,sizeof(struct co_info),1,ptr)){
			if(sorted[i]==read.seats&&strcmp(choice,read.purpose)==0&&read.flag==0){
				x=printstation(read);
			}

			
	}
	fseek(ptr,0,SEEK_SET);
	i++;
	}
	if(x==0)
	{
	 printf("No cars found,Returning to mainscreen.......");
	 sleep(2);
	 main();
	}
}
void pricehightolow(char choice[])
{
FILE* ptr;
	ptr=fopen("owner.bin","rb");
	struct co_info read;
	int count=0;
	while(fread(&read,sizeof(struct co_info),1,ptr)){
		if(strcmp(choice,read.purpose)==0&&read.flag==0)
			count++;
	}
	fseek(ptr,0,SEEK_SET);
	int c=0;
	int sorted[count];
		while(fread(&read,sizeof(struct co_info),1,ptr))
		{
		  
		  if(strcmp(choice,read.purpose)==0&&read.flag==0)
		   {
			sorted[c]=read.price;
			c++;
		    }
	  }
	int i=0,x=0;
	 sortlowtohigh(sorted,count);
	 removeduplicate(sorted,count);
	 fseek(ptr,0,SEEK_SET);
	 int j;
	for (j=0;j<count;j++){
	while(fread(&read,sizeof(struct co_info),1,ptr)){
			if(sorted[i]==read.price&&strcmp(choice,read.purpose)==0&&read.flag==0){
			printf("CarID: %d\t ",read.CID);
            printf("CarName: %s\t ",read.carname);
            printf("Model Year: %d\t ",read.mnum);
            printf("Seating Capacity: %d\t ",read.seats);
            printf("PricePerDay: %d\t ",read.price);
            printf("Reviews: %f\n",read.review);	
            x++;
			}

			
	}
	fseek(ptr,0,SEEK_SET);
	i++;
	}
	if(x==0)
	{
	 printf("No cars found,Returning to mainscreen.......");
	 sleep(2);
	 main();
	}
 
}
void pricelowtohigh(char choice[])
{
	FILE* ptr;
	ptr=fopen("owner.bin","rb");
	struct co_info read;
	int count=0;
	while(fread(&read,sizeof(struct co_info),1,ptr)){
		if(strcmp(read.purpose,choice)==0&&read.flag==0)
			count++;
	}
	int sorted[count];
	fseek(ptr,0,SEEK_SET);
	int c=0;
	while(fread(&read,sizeof(struct co_info),1,ptr)){
	  if(strcmp(read.purpose,choice)==0&&read.flag==0)
	   {
	   sorted[c]=read.price;
	   c=c+1;;
       }
	}
	
	int i=0,x=0;
	 sortlowtohigh(sorted,count);
	 removeduplicate(sorted,count);
	 fseek(ptr,0,SEEK_SET);
	 int j;
	for (j=0;j<count;j++){
	while(fread(&read,sizeof(struct co_info),1,ptr)){
		
			if(sorted[i]==read.price&&strcmp(read.purpose,choice)==0&&read.flag==0)
			{
			printf("CarID: %d\t ",read.CID);
            printf("CarName: %s\t ",read.carname);
            printf("Model Year: %d\t ",read.mnum);
            printf("Seating Capacity: %d\t ",read.seats);
            printf("PricePerDay: %d\t ",read.price);
            printf("Reviews: %f\n",read.review);
            x++;
			}

			
	}
	fseek(ptr,0,SEEK_SET);
	i++;
	}
	if(x==0)
	{
	 printf("No cars found,Returning to mainscreen.......");
	 sleep(2);
	 main();
	}			
}
void Reviews(char choice[])
{
    FILE *ptr;
	ptr=fopen("owner.bin","rb");
	struct co_info read;
	int count=0;
	while(fread(&read,sizeof(struct co_info),1,ptr)){
		if(strcmp(choice,read.purpose)==0&&read.flag==0)
			count++;
	}
	fseek(ptr,0,SEEK_SET);
	int c=0;
	float sorted[count];
		while(fread(&read,sizeof(struct co_info),1,ptr))
		{
		  
		  if(strcmp(choice,read.purpose)==0&&read.flag==0)
		   {
			sorted[c]=read.review;
			c++;
		    }
	  }
	int i=0,x=0;
	 reviewhightolow(sorted,count);
	 reviewremoveduplicate(sorted,count);
	 fseek(ptr,0,SEEK_SET);
	 int j;
	for (j=0;j<count;j++){
	while(fread(&read,sizeof(struct co_info),1,ptr)){
			if(sorted[i]==read.review&&strcmp(choice,read.purpose)==0&&read.flag==0){
			x=printstation(read);
			}

			
	}
	fseek(ptr,0,SEEK_SET);
	i++;
	}
	
	if(x==0)
	{
	 printf("\nNo cars found,Returning to mainscreen.......");
	 sleep(2);
	 main();
	}
}
char* getlocaltime(){
	time_t ttime = time(0);
    
    char* dt = ctime(&ttime);
    return dt;
}
int card(int price)
{
  char cardno[100];
  int i=0,c=0;
  printf("Enter your card no");
  fflush(stdin);
  gets(cardno);
  for(i=0;i<strlen(cardno);i++)
  {
   if(cardno[i]>47&&cardno[i]<58)
   {
   	c++;
   }
  }
  if(c!=strlen(cardno))
  {
   printf("Invalid characters entered ");
   return 0;
  }
  if(strlen(cardno)<6||strlen(cardno)>19)
  {
   printf("Invalid card no");
   return 0;
  }
  i=0;
  printf("Your credit card no is: ");
  while(i<strlen(cardno))
  {
   if(i%4==0)
   {
   	printf(" ");
   }
   printf("%c",cardno[i]);
   i++;
  }
  printf("\nAmount to be withdrawed from your account is %d",price);
}
int payment (int price)
{
	
	int mode,cash;
	
  printf("\t\t\t\t Checkout");
  printf("\nPress 1 if you want to pay card\n");
	printf("\nPress 2 if you want to pay cash\n");
	scanf("%d",&mode);
	switch(mode)
	{
	  case 1:
	  	{
	  	 card(price);
	  	 break;
		  }
	  case 2:
	  	{
	  	 printf("Enter amount of cash ");
	  	 scanf("%d",&cash);
	  	 if(cash>=price)
	  	 {
	  	  printf("change returned is %d\n",cash-price);
		   }
		else {
		printf("Insufficient money entered");
		printf("\nre-directing to mainpage...");
		sleep(2);
		main();
		return 0;
		break;
		  }}
	}
}
int Buy(struct User pass,int days,int price,char choice[])
{
 fflush(stdin);
 int ID;
 printf("\nEnter ID of the car you want to rent from the above list:    ");
 scanf("%d",&CID);
 system("cls");
 printf("Finding your car....\n");
 sleep(2);
 FILE *p;
 struct co_info car;
 p=fopen("owner.bin","rb");
 int i,flag=0,flag2=0;
 for(i=0;i<3;i++)
 {
 fseek(p,0,SEEK_SET);
 while(fread(&car,sizeof(struct co_info),1,p))
 {
 	if(flag>0&&flag<3)
 	{
 	  printf("Enter ID of the car you want to rent from the above list");
      scanf("%d",&CID);
	 }
 	if(car.CID==CID)
 	{
 	 if(strcmp(car.purpose,choice)==0)
 	 {
 	  printf("\t\t\t________________________________________________\n");
 	  printf("\t\t\t The car you have picked is %s\n",car.carname);
 	  price=price+days*car.price;
 	  printf("Your total price is %d\n",price);
 	  printf("\n_______________________________________________________\n");
 	  printf("\n\n");
 	  printf("Enter Y to confirm your order\nPress any  other character to go back to main page\n");
 	  char m[10];
 	  fflush(stdin);
	   gets(m);
 	  switch(strcmp(m,"Y")==0||strcmp(m,"y")==0)
 	  {
 	   case 1:
 	   	{
 	   	 system("cls");
 	   	 printf("Booking your Order........\n");
 	   	 sleep(2);
 	   	 printf("Congratulations your order has been confirmed!\n");
 	   	 printf("You will now be guided towards our Invoice and Payment Details Area");
		sleep(2);
		FILE *fr;
		fr=fopen("owner.bin","rb+");
		struct co_info read;
		while(fread(&read,sizeof(struct co_info),1,fr)){
				if (read.CID==CID){
					read.rcount++;
                    pass.CID=read.CID;
					fseek(fr,-sizeof(struct co_info),SEEK_CUR);
					fwrite (&read, sizeof(struct co_info), 1, fr);
					break;
				}
	
		}

		
 	   	

 	   	 return price;
 	   	 break;
		}
 	    default:
 	    {
	    main();
		break;
 	    }
	   }
	  }
	  else
	 {
	  printf("Your car is not listed in %s category and is not available for your uses please enter again\n");
	  flag++;
      }
      flag2++;
      continue;
	 }
	if(flag>3||flag2>3)
	{
	printf("We apologize for the inconvience\nNo cars found\n Exiting program......");
	char c=getchar(); 
	sleep(2);
	exit(0);
	}
	
 }
}
}
void filter(int choice,char pref[] )
{
  switch(choice)
  {
    case 1:
        { 
		  sleep(2);
	  	  system("cls");
	  	  NameQuery(pref);
	  	  break;
		  }
     case 2:
{
           
	  	  sleep(2);
	  	  system("cls");
	  	  ModelQuery(pref);
	  	  break;
		  
  }
  case 3:
  {
  	sleep(2);
	system("cls");
	SeatingQuery(pref);
	break;
  }
  case 4:
  {
  	sleep(2);
	system("cls");
	NameBrowse(pref);
	break;
  }
  case 5:
  {
  	sleep(2);
    system("cls");
	Modelbrowserecenttoearliest(pref);
	break;
  }
  case 6:
  {
  	sleep(2);
	system("cls");
    Modelbrowseearliesttorecent(pref);
    break;
  }
  case 7:
  {
  	sleep(2);
	system("cls");
	SeatingcapacityLowesttoHighest(pref); 
	break;
  }
  case 8:
  {
   sleep(2);
   system("cls");
   Seatingcapacityhighesttolowest(pref);
   break;
  }
  case 9:
  {
   sleep(2);
   system("cls");
   pricehightolow(pref);
   break;
  }
  case 10:
  {
  	sleep(2);
	system("cls");
	pricelowtohigh(pref);
	break;
  }
  case 11:
  {
  	 sleep(2);
	 system("cls");
	 Reviews(pref);
	 break;
  }
  default:
  {
  	printf("Invalid character");
  	break;
  }
}
}
int wedding(struct User pass,int price,char choice [])
{
struct co_info W;
printf("Loading Packages....");
int i;
 sleep(2);
 
 int Budget=3000,Normal=5000,Luxury=8000,Custom;
 printf("\nPlease specify what kind of package would you like\n1)Budget\n2)Normal\n3)Luxury\n4)Custom\n");
 scanf("%d",&i);
 switch (i)
 {
 	case 1:
 		{
 		 printf("You have selected the Budget package\nYour bill for decorations is %d Rs",Budget);
 		 price= price+Budget;

 		 break;
		 }
	case 2:
		{
		 printf("You have selected the Normal package\nYour bill for decorations is %d Rs",Normal);
		 price= price+Normal;
		 break;
		}
	case 3:
		{
		 printf("You have selected the Luxury package\nYour bill for decorations is %d Rs",Luxury);
		 price = price+Luxury;
		 break;
		}
	case 4:
		{
		 int flowers=3000,ribbons=2500,j;
		 printf("If you would like flowers only press 1\nIf you would like ribbons only press 2\n If you would like both press 3");
		 scanf("%d",&j);
		 switch(j)
		 { 
		 case 1:
		 	{
		 	 printf("You have selected the flowers only custom package\nYour bill for decorations is %d Rs\n",flowers);
		 	 price = price+flowers;
		 	 break;
			 }
		case 2:
			{
			 printf("You have selected the ribbons only custom package\nYour bill for decorations is %d Rs\n",ribbons);
			 price = price+ribbons;
			 break;
			}
		case 3:
			{
			 printf("You have selected the flowers and ribbons only custom package\nYour bill is %d Rs",flowers+ribbons);
			 price = price+(flowers+ribbons);
			 break;
			}
		default:
			{
			 char k;
			 printf("Invalid character entered\nIf you would like to exit press 0 or any other character\nIf you would like to go back to main wedding page press 1\n");
			 scanf("%c",&k);
			 switch(k)
			  {
				case '1':
					{
					wedding(pass,price,choice);
					}
				default:
					{
					 return 0;
					}
			  }
			}
		}
		break;
	 	}
	  default:
	    {    int k;
			 printf("Invalid character entered\nIf you would like to exit press 0 or any other character\nIf you would like to go back to main wedding page press 1\n");
			 scanf("%d",&k);
			 switch(k)
			  {
				case 1:
					{
					wedding(pass,price,choice);
					}
				default:
					{
					 return 0;
					}
		}
 }
 
}
fflush(stdin);
sleep(3);
system("cls");
 printf("\t\t\t\t Welcome to The Wedding Section of Wheels for Wheels");
 	
	printf("\nPress the following keys for your desired method of filtering ");
    printf("\n1,For searching for cars with a particular Model name.\n");
	printf("2,For searching for cars with a particular Model year.\n");
	printf("3,For searching for cars with a particular Seating capacity.\n");
	printf("4,For browsing all cars randomly by Model Name.\n");
	printf("5,For browsing all cars by Model year recent to earliest.\n");
	printf("6,For browsing all cars by Model year earliest to recent.\n");
	printf("7,For browsing all cars by Seating Capacity Lowest to Highest.\n");
	printf("8,For browsing all cars by Seating Capacity Highest to Lowest.\n");
	printf("9,For browsing all cars by Pricing Highest to Lowest.\n");
	printf("10,For browsing all cars by Pricing Lowest to Highest.\n");
	printf("11,For browsing all cars by their Owner's reviews\n");
	scanf("%d",&i);
	
filter(i,choice);
fflush(stdin);
	char ch;
	printf("\n__________________________________________________________________ \n");
	printf("If you want to rent a car Press 1\n");
	printf("If you want to go back to main menu any other character\n");
	scanf("%c",&ch);
	switch(ch)
	{
	  case '1':
	  	{
	  	 int day=1;
	  	 price= price+ Buy(pass,day,price,choice);
	  	 break;
		  }
	   default:
	    {
	      main();
	      break;
		}
	}
 return price;
}

int everyday(struct User pass,int price,char choice[])
{
 printf("Loading Everyday Section.....\n");
 sleep(2);
 system("cls");
 printf("\t\t\t\t Welcome to The Everyday Section of Wheels for Wheels\n");
 int day;
 printf("\t\t\t\tHow many days will you be needing the car: ");
 scanf("%d",&day);
 if(day>15)
 {
  price=price-2000;
  }
 if(day>30)
 {
  price=price-4000;
 }
    struct co_info E;
	int i;
	printf("\nPress the following keys for your desired method of filtering\n ");
    printf("1,For searching for cars with a particular Model name.\n");
	printf("2,For searching for cars with a particular Model year.\n");
	printf("3,For searching for cars with a particular Seating capacity.\n");
	printf("4,For browsing all cars randomly by Model Name.\n");
	printf("5,For browsing all cars by Model year recent to earliest.\n");
	printf("6,For browsing all cars by Model year earliest to recent.\n");
	printf("7,For browsing all cars by Seating Capacity Lowest to Highest.\n");
	printf("8,For browsing all cars by Seating Capacity Highest to Lowest.\n");
	printf("9,For browsing all cars by Pricing Highest to Lowest.\n");
	printf("10,For browsing all cars by Pricing Lowest to Highest.\n");
	printf("11,For browsing all cars by their Owner's reviews\n");
	scanf("%d",&i);
	fflush(stdin);
	FILE *p;
	int count=0;
	filter(i,choice);
	char ch;
		printf("\n__________________________________________________________________\n ");
	printf("If you want to rent a car Press 1\n");
	printf("If you want to go back to main menu any other character\n");
	scanf("%c",&ch);
	switch(ch)
	{
	  case '1':
	  	{
	  	 price= price+ Buy(pass,day,price,choice);
	  	 break;
		  }
	   default:
	    {
	      main();
	      break;
		}
	}


 return price;
}

int longdrive(struct User pass,int price,char choice[])
{
	struct co_info LD;
	printf("Loading Long-Drive Section.....\n");
 	sleep(2);
 	system("cls");
	int dist,days;
	printf("\t\t\t\t Welcome to The Long Drive Section of Wheels for Wheels\n");
	printf("\t\t\t\tRoughly for how many kilometers will you be needing the car: ");
	scanf("%d",&dist);
	printf("\t\t\t\tFor how many days will you be needing the car:  ");
	scanf("%d",&days);
	fflush(stdin);
	if(dist>300)
	{
	 price=price-3000;
	}
	if(dist>500)
	{
	 price=price-5000;
	}
	price=price+dist*50;
	int i;
	sleep(1);
	printf("Press the following keys for your desired method of filtering\n");
    printf("1,For searching for cars with a particular Model name.\n");
	printf("2,For searching for cars with a particular Model year.\n");
	printf("3,For searching for cars with a particular Seating capacity.\n");
	printf("4,For browsing all cars randomly by Model Name.\n");
	printf("5,For browsing all cars by Model year recent to earliest.\n");
	printf("6,For browsing all cars by Model year earliest to recent.\n");
	printf("7,For browsing all cars by Seating Capacity Lowest to Highest.\n");
	printf("8,For browsing all cars by Seating Capacity Highest to Lowest.\n");
	printf("9,For browsing all cars by Pricing Highest to Lowest.\n");
	printf("10,For browsing all cars by Pricing Lowest to Highest.\n");
	printf("11,For browsing all cars by their Owner's reviews\n");
	scanf("%d",&i);
	filter(i,choice);
	
	char ch;
		printf("\n_______________________________________________________________\n ");
	printf("If you want to rent a car Press 1\n");
	printf("If you want to go back to main menu any other character\n");
	scanf(" %c",&ch);
	switch(ch)
	{
	  case '1':
	  	{
	  	 price= price+ Buy(pass,days,price,choice);
	  	 break;
		  }
	   default:
	    {
	      main();
	      break;
		}
	}

	return price;
	
	
	
}
 
int preference(int i)
{
  switch(i)
  {
  	case 1:
  		{
  	     system("cls");
  		 return 1;
		  }
	case 2:
		{
		 system("cls");
		 return 2;
		}
	case 3:
		{
		 system("cls");
		 return 3;
		}
	default:
		{
		 system("cls");
		 printf("\t\t\tInvalid Character Entered");
		 int y;
		 printf("\nEnter any  number to exit. ");
		 scanf("%d",&y);
		 switch(y)
		 {
		 case 1:
		  {
		   return 4;
		  }
		 default:
		 	{
		 	return 0;
			 }
		}
		}
  }
}

void invoice(int mode,int preference,int price,struct User *ptr){
	struct co_info car;
	system("cls");
	printf("Displaying Invoice. Please wait....\n");
	char* localtime=getlocaltime();
	strcpy(ptr->time,localtime);
	ptr->CID=CID;
	sleep(2);
	system("cls");
	printf("\n\t\t\t\tInvoice:\n");
	printf("\t\t---------------------------------------------\n");
	if (mode==1){	
		strcpy(ptr->bookingmode,"Normal");
		printf("\t\t| Mode of Booking :------------- Normal\n");}
	if (mode==2){
		strcpy(ptr->bookingmode,"Emergency");
		printf("\t\t| Mode of Booking :------------- Emergency\n");}
	if (preference==1){
		strcpy(ptr->preference,"Everyday Use");
		printf("\t\t| Preference:--------- Everyday Use\n");}
	if (preference==2){
		strcpy(ptr->preference,"Wedding");
		printf("\t\t| Preference:------------------- Wedding\n");}
	if (preference==3){
		strcpy(ptr->preference,"Long Drive");
		printf("\t\t| Preference:--------- Long Drive\n");}
	printf("\t\t| Date of Issuance:----- %s",localtime);
	FILE* fptr;
	fptr=fopen("owner.bin","rb");
	while(fread(&car,sizeof(struct co_info),1,fptr)){
		if (ptr->CID==car.CID){
			printf("\t\t| Car Name:----- %s\n",car.carname);
			printf("\t\t| CarID:------- %d\n",car.CID);
		}
	}
	
	printf("\t\t---------------------------------------------\n");
	printf("\t\t| Amount to be paid: %d PKR\n",price);
	ptr->amountpaid=price;
	printf("\t\t---------------------------------------------\n");
	ptr->cancel=0;
	sleep(2);
}
displaycarowner(){
    system("cls");
    FILE *fp;
    fp=fopen("owner.bin","rb");
    struct co_info cread;
    printf("Please specify the domain you want to see the carowners from,that is :\n1)For every day use\n2)for wedding purpose\n3)for long drive\n4)All Domains \n5)To enter a particular carowner ID you want to see\nKindly enter enter the purpose from above mentioned options only .\n");
   char k;
   int ID;
   scanf(" %c",&k);
   char choice[10];
   if(k=='1')
   {
   strcpy(choice,"Everyday");
   }
  else if(k=='2')
  {
  strcpy(choice,"Wedding");
  }
  else if(k=='3')
  {
  strcpy(choice,"Long Drive");
  }
  else if(k=='4')
  {
   //do nothing will print normally
  } 
  else if(k=='5')
  {
   printf("Enter Carowner ID:  ");
   scanf("%d",&ID);
  }
  else
  {
  printf("Invalid character entered\n");
  printf("Returning to main menu.....\n");
  sleep(2);
  main();
  }
  
    while(fread(&cread,sizeof(struct co_info),1,fp)){
    	if ((k!='4'||k!='5')&&cread.rcount!=-1&&strcmp(choice,cread.purpose)==0)
       {printf("ID:---%d\nName:---%s\nCar Name:-----%s\nPreference:----%s\nAmount Per Day:---%d\nRides Done:--%d\n",cread.ID,cread.cname,cread.carname,cread.purpose,cread.price,cread.rcount);
        printf("\n\n");
    }
    else if(k=='4'&&cread.rcount!=-1)
    {
	printf("ID:---%d\nName:---%s\nCar Name:-----%s\nPreference:----%s\nAmount Per Day:---%d\nRides Done:--%d\n",cread.ID,cread.cname,cread.carname,cread.purpose,cread.price,cread.rcount);
    printf("\n\n");
    }
    else if(k=='5'&&cread.ID==ID&&cread.rcount!=-1)
    {
    	printf("ID:---%d\nName:---%s\nCar Name:-----%s\nPreference:----%s\nAmount Per Day:---%d\nRides Done:--%d\n",cread.ID,cread.cname,cread.carname,cread.purpose,cread.price,cread.rcount);
	    break;
	}
    }
    
   
     fclose(fp);

}
displayusers(){
    system("cls");
     FILE* fp;
   fp=fopen("user.bin","rb");
	struct User uread;
	int count=1;
	int k;
    printf("Please specify the domain you want to see the users from,that is :\n1)For every day use\n2)for wedding purpose\n3)for long drive\n4)All Domains \n5)To enter a particular userID you want to see\nKindly enter enter the purpose from above mentioned options only .\n");
  scanf(" %d",&k);
  int ID;
  char choice[10];
  if(k==1)
  {
  strcpy(choice,"Everyday");
  }
  else if(k==2)
  {
  strcpy(choice,"Wedding");
  }
  else if(k==3)
  {
  strcpy(choice,"Long Drive");
  }
  else if(k==4)
  {
   //do nothing will print normally
  }
  else if(k==5) 
  {
   
   printf("Enter User ID:  ");
   scanf("%d",&ID);
  }
  else
  {
  printf("Invalid character entered\n");
  printf("Returning to main menu.....\n");
  sleep(2);
  main();
  }
	while(fread(&uread,sizeof(struct User),1,fp)){
		
        if ((k!=4||k!=5)&&uread.cancel==0&&strcmp(choice,uread.preference)==0)
		{

        printf("\nPrinting User %d:\n",count);
		printf("UserID:--%d\nCarID:---%d\nName:---%s\n Email:----%s\n  Mode:-----%s\n Preference:----%s\n Amount:---%d\n Booking time:--%s",uread.ID,uread.CID,uread.username,uread.useremail,uread.bookingmode,uread.preference,uread.amountpaid,uread.time);
		printf("Your commission is %f",0.2*uread.amountpaid);
		if(uread.amountpaid==0)
		{
		 printf("\nThis user currently has no rides in progress");
		}
		printf("\n\n");
        count++;
		}	
		 if (k==4&&uread.cancel==0)
        {

        printf("\nPrinting User %d:\n",count);
		printf("UserID:--%d\nCarID:---%d\nName:---%s\nEmail:----%s\n  Mode:-----%s\n Preference:----%s\n Amount:---%d\n Booking time:--%s",uread.ID,uread.CID,uread.username,uread.useremail,uread.bookingmode,uread.preference,uread.amountpaid,uread.time);
		printf("Your commission is %f",0.2*uread.amountpaid);
		if(uread.amountpaid==0)
		{
		 printf("\nThis user currently has no rides in progress");
		}
		printf("\n\n");
        count++;
		}
		 if(k==5&&ID==uread.ID&&uread.cancel==0)
		{
		printf("UserID:--%d\nCarID:---%d\nName:---%s\n Email:----%s\n  Mode:-----%s\n Preference:----%s\n Amount:---%d\n Booking time:--%s",uread.ID,uread.CID,uread.username,uread.useremail,uread.bookingmode,uread.preference,uread.amountpaid,uread.time);
		printf("Your commission is %f",0.2*uread.amountpaid);
		if(uread.amountpaid==0)
		{
		 printf("\nThis user currently has no rides in progress");
		}
		break;
		}
    
	

}
fclose(fp);
}

deleteuser(){
    int ID;
    printf("Enter the USER ID whose account you want to cancel\n");
    fflush(stdin);
    scanf("%d",&ID);
    int flag=0;
     FILE* fp;
   fp=fopen("user.bin","rb+");
	struct User Uread;
	while(fread(&Uread,sizeof(struct User),1,fp)){
		if (Uread.ID==ID&&Uread.cancel==0){
		 printf("User Mr:%s has been found\nIf you want to confirm their removal press 1\nIf you want to cancel and go back to main page press any other key\n",Uread.username);
		 printf("Enter key:  ");
		 char A;
         fflush(stdin);
		 A=getchar();
		 switch(A)
		 {
		case '1':
		    
            printf("Deleting info....");
            Uread.cancel=1;
            flag=1;
            fseek(fp,-sizeof(struct User),SEEK_CUR);
            fwrite (&Uread, sizeof(struct User), 1, fp);
            break;
        
            default:
		
		  printf("Rerouting Back to mainpage.....");
		  sleep(2);
		  main();
		  break;
				
	}
        }	
	
    if (flag==1){
        printf("\nInfo deleted for User: ");
        puts(Uread.username);
        break;
    }

	
}
fclose(fp);
}
deletecarowner(){
	
	int ID;
    printf("Enter the ID of the CarOwner you want to delete ");
    scanf("%d",&ID);
	fflush(stdin);
    int flag=0;
     FILE* fp;
   fp=fopen("owner.bin","rb+");
	struct co_info read;
	while(fread(&read,sizeof(struct co_info),1,fp)){
		if(read.ID==ID)
		{
		 printf("The carowner has been found\nIf you want to confirm their removal press 1\nIf you want to cancel and go back to main page press any other key\n");
		 printf("Enter key:  ");
		 char A;
		 A=getchar();
		 switch(A)
		 {
		case '1':
		    {
            printf("Deleting info....");
            read.rcount=-1;
            flag=1;
            fseek(fp,-sizeof(struct co_info),SEEK_CUR);
            fwrite (&read, sizeof(struct co_info), 1, fp);
            break;
        }
		case '2':
		{
		  printf("Rerouting Back to mainpage.....");
		  sleep(2);
		  main();
		  break;
			}	
	}
    if (flag==1) {
        printf("Info deleted for User: ");
        puts(read.cname);
    }

	fclose(fp);
}
}
}
int login(){
    system("cls");
    char adminemail[100],adminpass[100];
        printf("\t\t\t\t\tCar Rental System\n");
	printf("\t\t\t\t\t----------------\n");
	printf("\t\t\t\t\t      Login\n");
	printf("\t\t\t\t\t-----------------");

	printf("\n");
	sleep(2);
    int i,j;
     char *email[100]={"admin 1","admin2","admin3"};
     char *pass[100]={"hello world","2","3"};
    for (j=0;j<3;j++){
         printf("\t\t\t\t\tEnter email: ");
    gets(adminemail);
    printf("\t\t\t\t\tEnter password: ");
    gets(adminpass);
    for (i=0;i<3;i++){
        if (strcmp(adminemail,email[i])==0){
            if (strcmp(adminpass,pass[i])==0){
                printf("Verifying Credentials.....\n");
                sleep(2);
                system("cls");
                
                printf("\t\t\t\tAccess Granted\n");
                printf("\t\t\t\tWelcome Mr %s",email[i]);
                return 1;
            }
        }
        
        
        
    }
    if (j==2) {printf("You've exceed max number of tries"); break;}
    printf("Re-Enter Credentials\n");
    
    }
}
//date and time
int day(int d,int m,int y) {
    int i,month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char* day[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};   
 


    // correction for leap year
    if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0))
        month[1] = 29;

    if (y < 1900 || m < 1 || m > 12 || d < 1 || d > month[m - 1]) {
        printf("This is an invalid date.\n");
        return 1;
    }

    for (i = 1900; i < y; i++)
        if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0))
            d += 366;
        else
            d += 365;

    for (i = 0; i < m - 1; i++) 
        d += month[i];

    printf("%s.\n", day[d % 7]);
    return 0;
}
//color change
void ClearConsoleToColors(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
   
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

     COORD coord = {0, 0};

     DWORD count;

     CONSOLE_SCREEN_BUFFER_INFO csbi;
    
     SetConsoleTextAttribute(hStdOut, wColor);
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          
          FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

          FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
    
          SetConsoleCursorPosition(hStdOut, coord);
     }
     return;
}
//color setting
void SetColorAndBackground(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}

//Rating

//struct User
//{
//	int ID;
//	char username[20];
//	char useremail[200];
//	char password[20];
//	char bookingmode[20];
//	char time[200];
//	char preference[200];
//	int amountpaid;
//	int cancel;
//	int CID;
//};

    struct CO_idpass{
	char cname[100];
	char email[100];
	char password[100];
	int ID};
int rating(int var)
{
	system("cls");
	printf("\t\t\t\t\tWelcome to the rating page\n");
    printf("\t\t\t\t---------------------------------\n");
	
	struct co_info ci;
	struct CO_idpass co;	
	struct User P;
	int comp;
	char opt;
	int com;

	FILE *fp;
	
	fp=fopen("owner.bin","rb");
	printf("You can only choose from the CID's below: \n");
	int z=0;
	while(fread(&ci,sizeof(struct co_info),1,fp))
	{
		if(var==ci.ID)
		{
			printf("|%d|\t",ci.CID);
			z=1;
		}
	}
	fclose(fp);
	
	if(z==0)
	{
		printf("\nSorry! You haven't rented any car yet so we couldn't find any record''");
	}
			
	printf("\nEnter the car ID regarding which you have complain : ");
	scanf("%d",&comp);

	

	fp=fopen("user.bin","rb");
	
	
	while(fread(&P,sizeof(struct User),1,fp))
	{
		if(comp==P.CID)
		{
			printf("Displaying User Information. Please wait....\n");

	sleep(2);
	printf("\n\t\t\t\tUser Information:\n");
	printf("\t\t---------------------------------------------\n");
	
	printf("\t\t| Name of Customer:-------------------------- %s\n",P.username);

	printf("\t\t| Mode of Booking :------------ %s\n",P.bookingmode);
	
	printf("\t\t| Preference:--------- %s\n",P.preference);

	printf("\t\t---------------------------------------------\n");	
	
	printf("\t\t| Amount Paid By Customer:------ %d\n",P.amountpaid);
	
	com=P.amountpaid*0.2;
	
	printf("\t\t| Admin Commision:----- %d\n",com);	
		
	printf("\t\t| Amount CarOwner receive:----- %d\n",P.amountpaid-com);
	
    printf("\t\t| Date of Issuance:----- %s\n",P.time);
	
	printf("\t\t---------------------------------------------\n");
	sleep(2);
}	
			
			
		}
	
	
	int num,sal;
	
	sal=(P.amountpaid-com);
	printf("SAl: %d",sal);
	
	printf("\n\n\nplease rate the user under the following criteria:\n\n\npress 5 if user didn't harm your car at all\npress 4 if there is slight scratch\npress 3 if there is a noticeable harm to the car\npress 2 if any major part of your car is broken or missing\npress 1 if your car has crushed from any side : ");
	scanf("%d",&num);
	
	if(num==5)
	{
		printf("\nThank you for your rating.\nwe hope your car's condition is all fine\n");
		printf("Your  is : %d.\n\nHave a nice day",sal);
	}
	else if(num==4)
	{
		printf("\nThank you for your rating\nwe have acknowledged your concern.\nA slight scratch cost 1000 Rupees maintainance charges which we will add to your earning\n");
		sal=sal+1000;
		printf("\nYour earning is : %d.\n\nHave a nice day",sal);
	} 
	else if(num==3)
	{
		printf("\nThank you for your rating\nwe have acknowledged your concern.\nA noticeable harm cost 3000 Rupees maintainance charges which we will add to your earning\n");
		sal=sal+3000;
		printf("\nYour earning is : %d.\n\nHave a nice day",sal);
	} 
	else if(num==2)
	{
		printf("\nThank you for your rating\nwe have acknowledged your concern.\nA major or minor part missing issue cost 7000 Rupees maintainance charges which we will add to your earning\n");
		sal=sal+7000;
		printf("\nYour earning is : %d.\n\nHave a nice day",sal);
	}
	else if(num==1)
	{
		printf("\nThank you for your rating\nwe have acknowledged your concern.\nWe are sorry for such huge harm,rupees 10000 maintainance charges will be add to your earning\n");
		sal=sal+10000;
		printf("\nYour earning is : %d.\n\nHave a nice day",sal);
	}
	
	else
	{
		printf("Please choose from numbers 1-5 only\n");
	}
	printf("\t\t Thank You for Viewing\n");
   	printf("For returning back to menu press Y\nFor Returning exiting the program press N\n");
	scanf(" %c",&opt);
	
	if(opt=='Y' || opt=='y')
	{
		main();
	}
	else if(opt=='N' || opt=='n')
	{
		exit(1);
	}
	
	else
	{
		printf("You haven't press the right key so the program is exiting\n");
		printf("Loading...");
		sleep(1);
		exit(1);
	}	
	
	return 0;
	
}





//Renting
	
int renting(var)
{
	struct CO_idpass co;
	struct co_info ci;
	int car=0,c;
	int pref;
	int *p;
	char opt;
	
	FILE *fp;

	printf("\t\t\t\t\t\tWelcome to the renting car page\n");
    printf("\t\t\t\t----------------------------------------------------------------- \n");
	printf("\t\t\t\tWe are pleased that you have choosen our service to rent your car\n");
    printf("\n\n\n\nYou must fill the following form to mention your car details\n\n");
	
	fp=fopen("owner.bin","ab");
	if(fp==NULL)
	{
		printf("Error!opening file");
		exit(1);
	}
	
   	ci.CID=0;
	fp=fopen("owner.bin","rb");
	while(fread(&ci,sizeof(struct co_info),1,fp))
	{
		ci.CID++;
	}
	fclose(fp);
	
    ci.ID=var;
   	printf("ID alloted to you at sign up was: %d\n",ci.ID);
	
	fp=fopen("owner.bin","ab");

   	printf("CID : %d\n",ci.CID);
	printf("Enter your full name :");
	gets(ci.cname);
	printf("Enter your contact number(11 digit only):");
	gets(ci.pnum);
	printf("Enter your address : ");
	gets(ci.add);
	printf("Enter the name of your car : ");
	gets(ci.carname);
	printf("Enter the model number of your car : ");
	scanf("%d",&ci.mnum);
	
	
	printf("Enter the starting duration of availibility of car in the format DD/MM/YYYY : ");
	scanf("%d/%d/%d",&ci.d,&ci.m,&ci.y);
	day(ci.d,ci.m,ci.y);
	printf("Enter the ending duration of availibility of car in the format DD/MM/YYYY : ");
	scanf("%d/%d/%d",&ci.de,&ci.me,&ci.ye);
	fflush(stdin);
	day(ci.de,ci.me,ci.ye);
	printf("Enter the seating capacity of car: ");
	scanf("%d",&ci.seats);
	printf("Enter the renting price of your car: ");
	scanf("%d",&ci.price);
	printf("Please specify the purpose of renting your car,that is :\nPress 1 for every day use\nPress 2 for wedding purpose\nPress 3 for long drive\nKindly enter enter the purpose from above mentioned options only :");
	scanf("%d",&pref);
	if(pref==1)
	{
		strcpy(ci.purpose,"Everyday");
	}
	if(pref==2)
	{
		strcpy(ci.purpose,"Wedding");
	}
	if(pref==3)
	{
		strcpy(ci.purpose,"Long Drive");
	}		

	
	ci.flag=0;
	ci.rcount=0;

    fwrite(&ci,sizeof(struct co_info),1,fp);    
    fclose(fp);
    printf("\n\t Thankyou for viewing");
   	printf("For returning back to menu press Y\nFor Returning exiting the program press N\n");
	scanf(" %c",&opt);
	
	if(opt=='Y' || opt=='y')
	{
		main();
	}
	else if(opt=='N' || opt=='n')
	{
		exit(1);
	}
	
	else
	{
		printf("You haven't press the right key so the program is exiting\n");
		printf("Loading...");
		sleep(1);
		exit(1);
	}	    
    
}


//payment


int paymentC(var)
{
 struct User P;	
 struct  co_info ci;
 FILE *fp;
system("cls");
	printf("\t\t\t\t\t\tWelcome to the payment page\n");
    printf("\t\t\t\t----------------------------------------------------------------- \n");
	printf("\t\t\t\tWe are pleased that you have choosen our service to rent your car\n");
 int com,num=0,i=0,a=0,n;
 
fp=fopen("user.bin","rb");
while(fread(&P,sizeof(struct User),1,fp))
{
	num++;
}

fclose(fp);

fp=fopen("user.bin","rb");
	int *p;
	p=(int*)calloc(num,sizeof(int));
	

while(fread(&P,sizeof(struct User),1,fp))
{
	  *(p+i)=P.CID;
       i++;
}

fclose(fp);


	

    printf("\n");

//for(i=0;i<num;i++)
//{
//	printf("CID: %d\n",*(p+i));
//}

//getting car owner cid
	fp=fopen("owner.bin","rb");
	if(fp==NULL)
	{
		printf("Error!opening file");
		exit(1);
	}
		n=var;
		while(fread(&ci,sizeof(struct co_info),1,fp))    
    {
    	if(ci.ID==n)
    	{
		
  		//printf("a: %d\n",a);
		a++;
	}
    }

    
    fclose(fp);
	int *k;
	k=(int*)calloc(a,sizeof(int));    

	fp=fopen("owner.bin","rb");
	if(fp==NULL)
	{
		printf("Error!opening file");
		exit(1);
	}

	    n=var;
		i=0;
		while(fread(&ci,sizeof(struct co_info),1,fp))    
    {

	//	printf("CO ID :%d\n",ci.ID);
		if(ci.ID==n)
		{
			*(k+i)=ci.CID;
			i++;
			printf("\n");
		}
	}
	fclose(fp);

//for(i=0;i<a;i++)
//{
//	printf("Car owner CID: %d\n",*(k+i));
//}	

for(i=0;i<a;i++)
{

int j=0;		
fp=fopen("user.bin","rb");

while(fread(&P,sizeof(struct User),1,fp))
{
			if(*(k+i)==*(p+j) )
			{
				invoiceC(P);
			
//        	printf("\nUser ID is: %d\n",P.ID);
//			printf("User email is: %s\n",P.useremail);
//			printf("User name is: %s\n",P.username);
//			printf("Enter the car ID that you have selected: %d\n",P.CID);
//			printf("The amount paid by user is : %d\n",P.amountpaid);
//			com=P.amountpaid*0.2;
//			printf("20 percent comission of admin is :%d\n",com);
//			printf("amount transferred to car owner is :%d\n",P.amountpaid-com);
//			printf("The time when user confirmed booking was :%s",P.time);				
//			printf("\n");	
			}
		j++;
    
}

fclose(fp);
}
char opt;
printf("\t\t Thank You for Viewing\n");
printf("\nFor returning back to main menu press Y\nFor Returning exiting the program press N\n");
	scanf(" %c",&opt);
	
	if(opt=='Y' || opt=='y')
	{
		system("cls");
		main();
	}
	else if(opt=='N' || opt=='n')
	{
		exit(1);
	}
	
	else
	{
		printf("You haven't press the right key so the program is exiting\n");
		printf("Loading...");
		sleep(1);
		exit(1);
	}
free(p);
free(k);
}



void invoiceC(struct User P)
{
	
	//struct User P;
	//FILE *fp;
	int com;
	printf("Displaying Invoice. Please wait....\n");

	sleep(2);
	printf("\n\t\t\t\tInvoice:\n");
	printf("\t\t---------------------------------------------\n");
	
	printf("\t\t| Name of Customer:-------------------------- %s\n",P.username);

	printf("\t\t| Mode of Booking :------------ %s\n",P.bookingmode);
	
	printf("\t\t| Preference:--------- %s\n",P.preference);

	printf("\t\t---------------------------------------------\n");	
	
	printf("\t\t| Amount Paid By Customer:------ %d\n",P.amountpaid);
	
	com=P.amountpaid*0.2;
	
	printf("\t\t| Admin Commision:----- %d\n",com);	
		
	printf("\t\t| Amount CarOwner receive:----- %d\n",P.amountpaid-com);
	
    printf("\t\t| Date of Issuance:----- %s\n",P.time);
	
	printf("\t\t---------------------------------------------\n");
	sleep(2);
}




//Record

//	struct co_info{
//	int ID;	
//	char carname[100];
//	char cname[100];
//	char add[100];
//	char purpose[100];
//	char pnum[11];
//	int mnum;
//    int d;
//	int m;
//	int y; 
//	int de;
//	int me;
//	int ye;
//	int rcount;
//	int CID;
//	};
record(var)
{
	//struct co_info ci;
	struct CO_idpass co;
	int car=0,c=0;
	char opt;
	struct co_info ci;
	int *p;
	
	FILE *fp;
    system("cls");
	printf("\t\t\t\t\t\tWelcome to the record page\n");
    printf("\t\t\t\t----------------------------------------------------------------- \n");
	printf("\t\t\t\tWe are pleased that you have choosen our service to rent your car\n");
    
	
	fp=fopen("owner.bin","rb");
	if(fp==NULL)
	{
		printf("Error!opening file");
		exit(1);
	}
		while(fread(&ci,sizeof(struct co_info),1,fp))    
    {
    	if(var==ci.ID)
{
						
    printf("\n\nYour ID is :%d\n",ci.ID);
	printf("CID: %d\n",ci.CID);		
   	printf("Data Entered by Mr : %s\n",ci.cname);
	printf("Phone number is : %s\n",ci.pnum);
	printf("Address is : %s\n",ci.add);
	printf("Name of the car is : %s\n",ci.carname);
	printf("Model number of the car is :%d\n",ci.mnum);
	printf("Starting duration of availibility of car in the format DD/MM/YYYY is :%d/%d/%d\n",ci.d,ci.m,ci.y);
	printf("Ending duration of availibility of car in the format DD/MM/YYYY is :%d/%d/%d\n",ci.de,ci.me,ci.ye);
	printf("purpose : %s\n",ci.purpose);
}
}
	fclose(fp);
	printf("\t\t Thank You for Viewing\n");
   	printf("For returning back to menu press Y\nFor Returning exiting the program press N\n");
	scanf(" %c",&opt);
	
	if(opt=='Y' || opt=='y')
	{
		main();
	}
	else if(opt=='N' || opt=='n')
	{
		exit(1);
	}
	
	else
	{
		printf("You haven't press the right key so the program is exiting\n");
		printf("Loading...");
		sleep(1);
		exit(1);
	}	
}
	
	 

//ID and password

//struct CO_idpass{
//	char cname[100];
//	char email[100];
//	char password[100];
//	int ID;

//};
menu(struct CO_idpass co)
{
		
	int n,car=0;

	
	system("cls");
	printf("\t\t\t\t\tWelcome to the main menu\n");
	printf("\t\t\t\t\t------------------------\n");
	printf("\n\n\n1)Renting Car\n2)Record\n3)Rate the user\n4)Payment details\n");
	printf("\n\n\nPress 1 if you want to visit Renting Car page");
	printf("\nPress 2 if you want to see your record: ");
	printf("\nPress 3 if you want to rate the user: ");
	printf("\nPress 4 if you want to see your payment details: ");
		
	scanf("%d",&n);
	fflush(stdin);
	int var;
	var=co.ID;
	if(n==1)
	{
		printf("Renting car page loading...");
		sleep(2);
		system("cls");	    
	    renting(var);
	}
	
	if(n==2)
	{
		printf("Record page loading...");
		sleep(2);
		system("cls");
		record(var);
		
		
	}
	if(n==3)
	{
		printf("Rating page opening");
		sleep(2);
		system("cls");
		rating(var);
	}
	if(n==4)
	{
		printf("Payment page opening");
		sleep(2);
		system("cls");
		paymentC(var);
	}
}




int main()
{	ClearConsoleToColors(15, 4);
	fflush(stdin);
	while(1){
	
		system("cls");
  printf("\t\t\t\tWelcome to Wheels For Wheels!....\n");
	sleep(2);
	printf("\t\t\t\tLoading App.....\n");
	sleep(4);
  int i;
  printf("Enter 1 if you are looking to rent a vehicle\n");
  printf("Enter 2 if you are looking to provide a vehicle\n");
  printf("Enter 3 if you are a admin\n");
  scanf("%d",&i);

  switch (i)
  {
  	case 1:
  		{
  	struct User user;
	struct User comp;
	
	system("cls");
	printf("\t\t\t\t\tCar Rental System\n");
	printf("\t\t\t\t\t----------------\n");
	printf("\t\t\t\t\t      Signup\n");
	printf("\t\t\t\t\t-----------------");

	printf("\n");
	int num,i,flag=0;
	char a[100],b[100];
	printf("\t\t\t\tPress 1 For Signup\n");
	printf("\t\t\t\tPress 2 For Login\n");
	printf("\t\t\t\t1- Signup\n");
	printf("\t\t\t\t2- Login\n");	
	printf("Enter: ");
	scanf("%d",&num);
	fflush(stdin);
	switch(num)
	{
	
	case 1:
		
		{
		FILE *p;
		p=fopen("user.bin","rb");
		printf("Please fill in the information to get registered\n");
		printf("Enter your name: ");
		fflush(stdin);
		gets(user.username);
		printf("Enter email address:");
		fflush(stdin);
		gets(user.useremail);
		while(fread(&comp,sizeof(struct User),1,p))
		{
		 if(strcmp(comp.useremail,user.useremail)==0)
		 {
		   printf("This email is already registered to another account\n");
		   printf("You are being redirected to main page......");
		   sleep(2);
		   main();
		   
		 }
		}
		fclose(p);
		printf("Enter password:");
		fflush(stdin);
		gets(user.password);
		printf("Successfully signed up\n");
		p=fopen("user.bin","rb");
		int high=-1;
		struct User read;
		while(fread(&read,sizeof(struct User),1,p)){
			if (read.ID>high) high=read.ID;
		}
		high++;
		user.ID=high;
		sleep(2);
		break;
	}
		
	case 2:
	{
		FILE *str;
	str=fopen("user.bin","rb");
	if(str==NULL)
	{
	 printf("Error");
	 exit(1);
	}
	int x=0,z=0;
	for(i=0;i<3;i++)
	{
		printf("Enter the email:");
		fflush(stdin);
		gets(a);
		printf("Enter the password:");
		fflush(stdin);
		gets(b);
		fseek(str,0,SEEK_SET);
		 while(fread(&comp,sizeof(struct User),1,str))
			{
			if(strcmp(a,comp.useremail)==0)
			{
				if(strcmp(b,comp.password)==0)
				{
					user.ID=comp.ID;
					strcpy(user.username,comp.username);
					strcpy(user.useremail,comp.useremail);
					strcpy(user.password,comp.password);
					printf("Welcome %s\n",user.username);
					
					printf("Loading Menu...\n");
					sleep(2);
					x++;
				}
				
			}
			if(x>0)
			{
			break;}
			else
			{ 
			z++;
		   }
		}
		if(x>0)
		break;
		flag++;
		printf("Incorrect password\n");
		}
		break;
		
}
	case 3:
	{
		printf("Invalid value");
		printf("\nRe-directing to main page...");
		sleep(2);
		main();
	}
	}
	if (flag>=3)
	{
		printf("\nEntered incorrect password too many times");
        sleep(2);
		system("cls");
		printf("\nProgram Ending....");
		sleep(2);
		exit(1);
	}
	system("cls");
	int j,price=0,mode,cash;
	printf("Welcome %s\n",user.username);
	char key;
	if(num==2)
	{
	printf("\nEnter 1 for View any of your past bookings\n\n");
	printf("Enter any other key to continue towards your booking section\n\n");
	
	int count=0;
	fflush(stdin);
	scanf("%c",&key);
	if(key=='1'){
			FILE*fpptr;
			fpptr=fopen("user.bin","rb");
			struct User past;
			
			while(fread(&past,sizeof(struct User),1,fpptr)){
				
				if(strcmp(user.useremail,past.useremail)==0){
				printf("Displaying Past record #%d . Please wait....\n",++count);
				sleep(2);
			printf("\n\t\t\t\tInvoice:\n");
			printf("\t\t---------------------------------------------\n");
			printf("\t\t| Mode of Booking :------------- %s\n",past.bookingmode);
			printf("\t\t| Preference:-------------------%s\n",past.preference);
			printf("\t\t| Date of Issuance:----- %s",past.time);
			FILE* f;
			f=fopen("owner.bin","rb");
			struct co_info car;
			while(fread(&car,sizeof(struct co_info),1,f)){
			if (past.CID==car.CID){
			printf("\t\t| Car Name:----- %s\n",car.carname);
			printf("\t\t| CarID:------- %d\n",car.CID);
		}}
			printf("\t\t---------------------------------------------\n");
			printf("\t\t| Amount paid-----: %d PKR\n",past.amountpaid);
			printf("\t\t---------------------------------------------\n");
			sleep(2);	
				}
			}
		}
			
	
	if(count>0)
	printf("Thankyou for viewing past history\n");
	if (count==0&&key=='1') 
	printf("No past records as of now\nArranging Booking for you in just a moment.....\n");
	if(key=='1')
	{
	printf("Press L to Logout\n");
	printf("Press any other key to continue booking\n");
	fflush(stdin);
	scanf("%c",&key);
}
	if (key=='L'){
		printf("\n\n%s We are logging you out.....\n",user.username);
		printf("Have a nice day!");
		sleep(2);
		printf("\nLogged Out!");
		sleep(1);
		main();
	}		
	sleep(2);
	}

	system("cls");
	printf("\nPress 1 for normal booking\n");
	printf("Press 2 for emergency booking\n");
	scanf("%d",&j);
	switch (j)
	{
	  case 1:
	  	{
		 printf("Normal Booking Confirmed\n");
		 sleep(1);
		 printf("Loading Booking Menu....\n");
		 sleep(3);
	  	 break;
		  }
	  case 2:
	  	{
		printf("Emergency Booking Confirmed\n");
		 sleep(1);
		 printf("Loading Booking Menu....\n");
		 sleep(3);
	  	 price= 4000+price;
	  	 break;
		  }
	  default:
	  	{
	  	 printf("Invalid character entered");
	  		printf("\nRe-directing to mainpage..");
			  sleep(1);
			  main();
		  }
	}
  system("cls");
  int k,x,p1=0,p2=0,p3=0;
  printf("Please specify the purpose of renting a car,that is :\n1)For every day use\n2)for wedding purpose\n3)for long drive\nKindly enter enter the purpose from above mentioned options only :\n");
  scanf("%d",&k);
  char choice[200];
  x=preference(k);
  if(x==1)
  {
  strcpy(choice,"Everyday");
  p1=everyday(user,price,choice);
  }
  else if(x==2)
  {
  strcpy(choice,"Wedding");
  p2=wedding(user,price,choice);
  }
  else if(x==3)
  {
  strcpy(choice,"Long Drive");
  p3=longdrive(user,price,choice);
  }
  else{
	  printf("invalid key entered\n");
	  printf("Re-directing to main page....");
	  sleep(1);
	  main();
  } 
  
  
  sleep(2);
  price=price+p1+p2+p3;
  
     
	struct User *ptr=&user;
	struct User de;
	invoice(j,x,price,ptr);
	payment(price);

    FILE* fptr;
	FILE* fp;
	fptr=fopen("user.bin","ab");
	fwrite (&user, sizeof(struct User), 1, fptr);
	fclose(fptr);
	fflush(stdin);
	printf("\tBooking Done\n\tRedirecting to main page");
	sleep(3);
	main();
		  }
	case 2:
		{
		  
	system("cls");
	
	printf("\t\t\t\t\tWelcome to Car Owner Section\t\t    \n*");
	printf("\t\t\t\t\t----------------\n");
	printf("\t\t\t\t\tSignup page     \n");
	printf("\t\t\t\t\t-----------------");
	
		printf("\n");
	sleep(2);
	printf("\t\t\t\tIf you are new to this page Press 1 For Signup\n");
	printf("\t\t\t\tIf you already have an account Press 2 For Login\n");
    struct CO_idpass co; 	
	int num,i=0,z=0,flag=0,c;
	char email[100];char pass[100],name[100];
	FILE *fpr;
	printf("\t\t\t\t1- Signup\n");
	printf("\t\t\t\t2- Login\n");
		
	printf("\n  Enter: ");
	scanf("%d",&num);
	fflush(stdin);	
		switch(num)
	{
	
	case 1:
		
	{
	    fpr=fopen("id password.bin","rb");
		printf("Please fill in the information to get registered\n");
		printf("Enter your name:");
		gets(name);		
		printf("Enter email address:");
		gets(email);
		printf("Enter password:");
		gets(pass);
    c=0;
	while(fread(&co,sizeof(struct CO_idpass),1,fpr))
	{

	      if(strcmp(co.email,email)==0 || strcmp(co.password,pass)==0)
	    {
	    	z=1;
		}
		c++;
	}	
	
		if(z==1)
	{
		printf("\n\nYour email matches with another record");
		z=0;
		exit(1);
	}
	fclose(fpr);
	
    fpr=fopen("id password.bin","ab");   
    printf("\ntotal number of people are :%d\n",c);
    co.ID=10000;
    co.ID=co.ID+c;
    printf("ID given to you is :%d\n",co.ID);
    
	strcpy(co.cname,name);
	strcpy(co.email,email);
	strcpy(co.password,pass);
	strcpy(email,"NULL");
	strcpy(pass,"NULL");
	
    fwrite(&co,sizeof(struct CO_idpass),1,fpr);
  	fclose(fpr);
	printf("\nSuccessfully signed up\n");

	sleep(2);
	printf("Please re-enter credentials\n");
	sleep(2);
}

	case 2:
	{
			
		for(i=0;i<3;i++)
		{
		
	    fpr=fopen("id password.bin","rb");	
		printf("Enter the email:");
		gets(email);
		printf("Enter the password:");
		gets(pass);
				
	    while(fread(&co,sizeof(struct CO_idpass),1,fpr))
	  {

	      if(strcmp(co.email,email)==0 && strcmp(co.password,pass)==0)
	    {	    	
			printf("Welcome %s\n",co.cname);
			flag=1;
			sleep(1);
			printf("Loading menu page...");
			sleep(2);
		    menu(co);	
			exit(1);
			break;
		}
		
	}
	strcpy(email,"NULL");
	strcpy(pass,"NULL");
	printf("Incorrect email or password\n");
}
	if(i>=3)
	{
		printf("Entered incorrect password too many times\n");
		printf("Exiting...");
		sleep(2);
		exit(1);
	}
}
}

}

//Menu section	

		 
		
	case 3:
	
		{
			fflush(stdin);
	 if (login()!=1) exit(1);
    while (1){
    
    char choice;
    printf("\nPress 1 if you want to display all bookings");
    printf("\nPress 2 to display all car records\n");
	printf("\nPress any key to logout\n");
	fflush(stdin);
    scanf("%c",&choice);
	int cnclbook;
    switch (choice)
    {
    case '1':
        displayusers();
        
        printf("\nDo you want to cancel a booking?\n");
        printf("Press 1 for cancelling\n");
        scanf("%d",&cnclbook);
        if (cnclbook==1) deleteuser();

        break;
    
    case '2':
        displaycarowner();
		
        printf("\nDo you want to cancel a booking?\n");
        printf("Press 1 for cancelling\n");
        scanf("%d",&cnclbook);
        if (cnclbook==1) deletecarowner();
        break;
    default:
		printf("Logging you out...");
		printf("\nRedirecting to main page");
		sleep(2);
		main();
        break;
    }

    }

		  break;
		}
	default:
	   {
	   	printf("Invalid value");
	   	break;
	   }
  }
  printf("\nPress any key to logout...");
  fflush(stdin);
  getch();
	}
  }
  
