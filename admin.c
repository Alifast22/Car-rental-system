#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h> 

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
	char preference[200];
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

displaycarowner(){
    system("cls");
    FILE *fp;
    fp=fopen("owner.bin","rb");
    struct co_info cread;
    printf("\nName\t\tCar\t\tModel\tSeating Capacity\tModeoftransportation\n");
    printf("Please specify the domain you want to see the carowners from,that is :\n1)For every day use\n2)for wedding purpose\n3)for long drive\n4)All Domains \n5)To enter a particular carowner you want to see\nKindly enter enter the purpose from above mentioned options only .\n");
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
    	if ((k!='4'||k!='5')&&cread.rcount!=-1&&strcmp(choice,cread.preference)==0)
       {printf("ID:---%d\nName:---%s\nCar Name:-----%s\nPreference:----%s\nAmount Per Day:---%d\nRides Done:--%d\n",cread.ID,cread.cname,cread.carname,cread.preference,cread.price,cread.rcount);
        printf("\n\n");
    }
    else if(k=='4')
    {
	printf("ID:---%d\nName:---%s\nCar Name:-----%s\nPreference:----%s\nAmount Per Day:---%d\nRides Done:--%d\n",cread.ID,cread.cname,cread.carname,cread.preference,cread.price,cread.rcount);
    printf("\n\n");
    }
    else if(k=='5'&&cread.ID==ID)
    {
    	printf("ID:---%d\nName:---%s\nCar Name:-----%s\nPreference:----%s\nAmount Per Day:---%d\nRides Done:--%d\n",cread.ID,cread.cname,cread.carname,cread.preference,cread.price,cread.rcount);
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
    printf("Please specify the domain you want to see the users from,that is :\n1)For every day use\n2)for wedding purpose\n3)for long drive\n4)All Domains \n5)To enter a particular user you want to see\nKindly enter enter the purpose from above mentioned options only .\n");
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
		printf("\n\n");
        count++;
		}	
		 if (k==4&&uread.cancel==0)
        {

        printf("\nPrinting User %d:\n",count);
		printf("UserID:--%d\nCarID:---%d\nName:---%s\nEmail:----%s\n  Mode:-----%s\n Preference:----%s\n Amount:---%d\n Booking time:--%s",uread.ID,uread.CID,uread.username,uread.useremail,uread.bookingmode,uread.preference,uread.amountpaid,uread.time);
		printf("Your commission is %f",0.2*uread.amountpaid);
		printf("\n\n");
        count++;
		}
		 if(k==5&&ID==uread.ID&&uread.cancel==0)
		{
		printf("UserID:--%d\nCarID:---%d\nName:---%s\n Email:----%s\n  Mode:-----%s\n Preference:----%s\n Amount:---%d\n Booking time:--%s",uread.ID,uread.CID,uread.username,uread.useremail,uread.bookingmode,uread.preference,uread.amountpaid,uread.time);
		printf("Your commission is %f",0.2*uread.amountpaid);
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
		if (Uread.ID==ID){
		 printf("User Mr:%s has been found\nIf you want to confirm their removal press 1\nIf you want to cancel and go back to main page press any other key\n",Uread.username);
		 printf("Enter key:  ");
		 char A;
         fflush(stdin);
		 A=getchar();
		 switch(A)
		 {
		case '1':
		    {
            printf("Deleting info....");
            Uread.cancel=1;
            flag=1;
            fseek(fp,-sizeof(struct User),SEEK_CUR);
            fwrite (&Uread, sizeof(struct User), 1, fp);
            break;
        }
            default:
		{
		  printf("Rerouting Back to mainpage.....");
		  sleep(2);
		  main();
		  break;
			}	
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
    fflush(stdin);
    gets(adminemail);
    printf("\t\t\t\t\tEnter password: ");
    fflush(stdin);
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
int main(){
    if (login()!=1) exit(1);
    while (1){
    
    int choice;
    printf("\nPress 1 if you want to display all users");
    printf("\nPress 2 to display all car owners\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        displayusers();
        int cnclbook;
        printf("\nDo you want to cancel a booking?\n");
        printf("Press 1 for cancelling\n");
        scanf("%d",&cnclbook);
        if (cnclbook==1) deleteuser();

        break;
    
    case 2:
        displaycarowner();
        
        break;
      default:
        break;
    }

    }
}   
