#include<stdio.h>
#include<conio.h>
#include <unistd.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>

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
void rating(int var)
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

struct CO_idpass{
	char cname[100];
	char email[100];
	char password[100];
	int ID;

};
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
{
	ClearConsoleToColors(15, 4);
	system("cls");
	printf("*************************************************************************************\n*");
	printf("\t\t\t\t\tWelcome to Car Owner Section\t\t    *\n*");
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
