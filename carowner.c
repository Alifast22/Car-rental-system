#include <stdio.h>
#include <stdlib.h>

main()
{
	char years[10],yeare[10],name[100];
	int purpose,car=0,mnum;
	
	printf("Enter the name of your car : ");
	scanf("%s",&name);
	printf("Enter the model number of your car : ");
	scanf("%d",&mnum);
	
	printf("Enter the starting duration of availibility of car in the format DD/MM/YYYY : ");
	scanf("%s",&years);
	printf("Enter the starting ending duration of availibility of car in the format DD/MM/YYYY : ");
	scanf("%s",&yeare);
	printf("Please specify the purpose of renting your car,that is :\npress 1 For every day use\npress 2 for wedding purpose\npress 3 for long drive\nKindly enter enter the purpose from above mentioned options only :");
	scanf("%d",&purpose);
	system("cls");
	printf("\n\t\t\t\tReceipt:\n");
	
	printf("\t\t| Name of your car is :------------- %s\n",name);
	printf("\t\t| Model number of your car is :--------- %d\n",mnum);
	printf("\t\t| Your booking duration starts from : --------- %s\n\t\t| Your booking duration ends on :--------- %s\n",years,yeare);
	printf("\t\t----------------------------------------------------------\n");
	printf("\t\t");
	if(purpose==1)
	{
		printf("We will rent your car for every day use only\n");
	}
	if(purpose==2)
	{
		printf("We will rent your car for marriages use only\n");
	}
	if(purpose==3)
	{
		printf("We will mark rent your car for long drives use only\n");
	}
	car++;
	count(car);

	
}


count(int car)
{
	int sal=10000;
	printf("\nYou have rented %d cars",car);
	if (car>=20)
	{
		printf("\nWow! you have rented more than 20 cars!\nAs a reward we are giving you a bonus of 20 percent of your annual income.");
		sal=sal*0.2;
		printf("Your bonus is : %d\n",sal);
	}
	
}
