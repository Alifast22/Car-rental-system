#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
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
  		  //User();
  		  break;
		  }
	case 2:
		{
		  //Provider();
		  break;
		}
	case 3:
		{
		  //Admin();
		  break;
		}
	default:
	   {
	   	printf("Invalid value");
	   	break;
	   }
  }
  
  
  }
  