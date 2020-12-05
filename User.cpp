#include<stdio.h>
#include<string.h>
#include <conio.h>
#include <unistd.h>
#include <stdlib.h>
int card(int price)
{
  char cardno[100];
  int i=0,c=0;
  printf("Enter your card no: ");
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
int booking(){
	printf("Loading your booking menu......\n");
	sleep(2);
	int j;
	printf("Press 1 for normal booking\n");
	printf("Press 2 for emergency booking(extra charges)\n");
	scanf("%d",&j);
	sleep(2);
	int price=10000,mode,cash;
	float time;
	
	switch (j)
	{
	  case 1:
	  	{
	  	 break;
		  }
	  case  2:
	  	{
	  	 price= 4000+price;
	  	 break;
		  }
	  default:
	  	{
	  	 printf("Invalid character entered");
	  	 
		  }
	}
	
	
	do
	{	
		printf("Enter time required for car in days\n");
		scanf("%f",&time);
	} while (time<0);
	
	if(time>15&&time<30)
	{
	 price= price-2000;
	}
	if(time>30)
	{
	 price= price-4000;
	}
	printf("Payment: %d\n",price);
	printf("Press 1 if you want to pay card\n");
	printf("Press 2 if you want to pay cash\n");
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
		 printf("Enter amount of cash: ");
	  	 scanf("%d",&cash);
	  	 if(cash>=price)
	  	 {
	  	  printf("change returned is %d",cash-price);
		   }
		else 
		printf("Insufficient money entered");
	
		break;
		  }
	}
	return price;
}



int main()
{
	int num,i;
	
	char  email[100]={"m.ali"},pass[100]={"ali22"};
	
	char a[100],b[100];
	system("cls");
	printf("\t\t\t\t\tWheels For Wheels!\n");
	printf("\n");
	sleep(2);
	printf("\t\t\t\tPress 1 if you want to register \n\t\t\t\tPress 2 if if you want to login :");
	scanf("%d",&num);
	switch(num)
	{
	
	case 1:
		
		printf("Please fill in the information to get registered\n");
		printf("Enter your name");
		gets(a);
		
		printf("Enter email address");
		gets(email);
		printf("Enter password");
		gets(pass);
		
	case 2:
		
		for(i=0;i<3;i++)
		{
		printf("Enter the email:");
		scanf("%s",a);
		printf("Enter the password:");
		scanf("%s",b);
		
			if(strcmp(a,email)==0)
			{
				if(strcmp(b,pass)==0)
				{
					printf("\t\t\t\tWeclcome %s\n",email);
					sleep(3);
					
					system("cls");
					break;
				}
				
			}
			printf("Incorrect password"); 
		}
		
		
	}
	
	int j,price;
	
	price=booking();
	
	
}
