#include<stdio.h>
#include<conio.h>
#include <unistd.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>
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
  scanf("%s",&cardno);
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
int payment (int price){
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
	  	  printf("change returned is %d",cash-price);
		   }
		else 
		printf("Insufficient money entered");
		return 0;
		break;
		  }
	}
}
int wedding(int price)
{
	printf("Loading Packages....");
 sleep(2);
 system("cls");
 printf("\t\t\t\t Welcome to The Wedding Section of Wheels for Wheels");
 int Budget=3000,Normal=5000,Luxury=8000,Custom,i;
 printf("\nPlease specify what kind of package would you like\n1)Budget\n2)Normal\n3)Luxury\n4)Custom\n");
 scanf("%d",&i);
 switch (i)
 {
 	case 1:
 		{
 		 printf("You have selected the Budget package\nYour bill for decorations is %d Rs",Budget);
 		 price= price+Budget;
 		 return price;
 		 break;
		 }
	case 2:
		{
		 printf("You have selected the Normal package\nYour bill for decorations is %d Rs",Normal);
		 price= price+Normal;
 		 return price;
		 break;
		}
	case 3:
		{
		 printf("You have selected the Luxury package\nYour bill for decorations is %d Rs",Luxury);
		 price = price+Luxury;
 		 return price;
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
 		     return price;
		 	 break;
			 }
		case 2:
			{
			 printf("You have selected the ribbons only custom package\nYour bill for decorations is %d Rs\n",ribbons);
			 price = price+ribbons;
 		     return price;
			 break;
			}
		case 3:
			{
			 printf("You have selected the flowers and ribbons only custom package\nYour bill is %d Rs",flowers+ribbons);
			 price = price+(flowers+ribbons);
 		     return price;
			 break;
			}
		default:
			{
			 char k;
			 printf("Invalid character entered\nIf you would like to exit press 0 or any other character\nIf you would like to revise your choices press 1\n");
			 scanf("%c",&k);
			 switch(k)
			  {
				case '1':
					{
					wedding(price);
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
			 printf("Invalid character entered\nIf you would like to exit press 0 or any other character\nIf you would like to revise your choices press 1\n");
			 scanf("%d",&k);
			 switch(k)
			  {
				case 1:
					{
					wedding(price);
					}
				default:
					{
					 return 0;
					}
		}
 }
 
}
}

int everyday(int price)
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
 return price;
}

int longdrive(int price)
{
	printf("Loading Long-Drive Section.....\n");
 	sleep(2);
 	system("cls");
	int dist;
	printf("\t\t\t\t Welcome to The Long Drive Section of Wheels for Wheels\n");
	printf("\t\t\t\tRoughly for how many kilometers will you be needing the car: ");
	scanf("%d",&dist);
	if(dist>300)
	{
	 price=price-3000;
	}
	if(dist>500)
	{
	 price=price-5000;
	}
	price=price+dist*50;
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
		 printf("\nEnter 1 if you want to enter another number\nEnter any other number if you want to exit. ");
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

void invoice(int mode,int preference,int price){
	system("cls");
	printf("Displaying Invoice. Please wait....\n");
	char* localtime=getlocaltime();
	sleep(2);
	system("cls");
	printf("\n\t\t\t\tInvoice:\n");
	printf("\t\t---------------------------------------------\n");
	if (mode==1)	
		printf("\t\t| Mode of Booking :------------- Normal\n");
	if (mode==2)
		printf("\t\t| Mode of Booking :------------- Emergency\n");
	if (preference==1)
		printf("\t\t| Preference:--------- Everyday Use\n");
	if (preference==2)
		printf("\t\t| Preference:------------------- Wedding\n");
	if (preference==3)
		printf("\t\t| Preference:--------- Long Drive\n");
	printf("\t\t| Date of Issuance:----- %s",localtime);
	
	printf("\t\t---------------------------------------------\n");
	printf("\t\t| Amount to be paid: %d PKR\n",price);
	printf("\t\t---------------------------------------------\n");
	sleep(2);

}



//-x-x-x-x--x-x-x-xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx-x-x-x-x-x-x-//


int main()
{
	system("cls");
	printf("\t\t\t\t\tCar Rental System\n");
	printf("\t\t\t\t\t----------------\n");
	printf("\t\t\t\t\t      Signup\n");
	printf("\t\t\t\t\t-----------------");

	printf("\n");
	sleep(2);
	int num,i,flag=0;
	char email[100]={"m.ali"},pass[100]={"ali22"},name[100]={"ali"};
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
		
		printf("Please fill in the information to get registered\n");
		printf("Enter your name: ");
		gets(name);
		printf("Enter email address:");
		gets(email);
		printf("Enter password:");
		gets(pass);
		printf("Successfully signed up\n");
		sleep(2);
		printf("Please re-enter credentials\n");
		sleep(2);
		
		
	case 2:
		
		for(i=0;i<3;i++)
		{
		printf("Enter the email:");
		gets(a);
		printf("Enter the password:");
		gets(b);
		
			if(strcmp(a,email)==0)
			{
				if(strcmp(b,pass)==0)
				{
					printf("Welcome %s\n",name);
					 flag=1;
					sleep(1);
					printf("Loading Booking Menu...");
					sleep(2);
					break;
				}
				
			}
			printf("Incorrect password\n"); 
		}
		
		
	}
	if (flag!=1){
		
		printf("\nEntered incorrect password too many times");

		sleep(2);
		system("cls");
		printf("\nProgram Ending....");
		sleep(2);
		exit(1);
	}
	system("cls");
	int j,price=10000,mode,cash;
	
	printf("Press 1 for normal booking\n");
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
	  case  2:
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
	  	 return 0;
		  }
	}
  system("cls");
  int k,x,p1=0,p2=0,p3=0;
  printf("Please specify the purpose of renting a car,that is :\n1)For every day use\n2)for wedding purpose\n3)for long drive\nKindly enter enter the purpose from above mentioned options only :\n");
  scanf("%d",&k);
  x=preference(k);
  if(x==1)
  {
  p1=everyday(price);
  }
  if(x==2)
  {
  p2=wedding(price);
  }
  if(x==3)
  {
  p3=longdrive(price);
  }
  if(x==4)
  {
   main();
  }
  sleep(2);
  price=price+p1+p2+p3;
  sleep(2);
	invoice(j,x,price);
	payment(price);
}