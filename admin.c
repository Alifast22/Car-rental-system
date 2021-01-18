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
displaycarowner(){
    system("cls");
    FILE *fp;
    fp=fopen("owner.bin","rb");
    struct co_info cread;
    printf("\nName\t\tCar\t\tModel\tSeating Capacity\tPrice\tPurpose\t   Rent Count\n");
    while(fread(&cread,sizeof(struct co_info),1,fp)){
        
        printf("%s   %s\t %d \t\t%d\t\t%d\t %s\t %d\n",cread.cname,cread.carname,cread.mnum,cread.seats,cread.price,cread.purpose,cread.rcount);
    }

}
displayusers(){
    system("cls");
     FILE* fp;
   fp=fopen("user.bin","rb");
	struct User read;
	int count=1;
	while(fread(&read,sizeof(struct User),1,fp)){
        if (read.cancel==0){

        printf("\nPrinting User %d:\n",count);
		printf(" ID:---%d\n Name:---%s\n Email:----%s\n Mode:-----%s\n Preference:----%s\n Amount:---%d\n Booking time:--%s",read.ID,read.username,read.useremail,read.bookingmode,read.preference,read.amountpaid,read.time);
		count++;}	
	}
	fclose(fp);

}
deleteuser(){
    char name[20];
    printf("Enter the name of user to cancel the booking: ");
    fflush(stdin);
    gets(name);
    int flag=0;
     FILE* fp;
   fp=fopen("user.bin","rb+");
	struct User read;
	while(fread(&read,sizeof(struct User),1,fp)){
		if (strcmp(read.username,name)==0){
            printf("Deleting info....");
            read.cancel=1;
            flag=1;
            fseek(fp,-sizeof(struct User),SEEK_CUR);
            fwrite (&read, sizeof(struct User), 1, fp);
            break;
        }	
	}
    if (flag==1) {
        printf("Info deleted for User: ");
        puts(name);
    }

	fclose(fp);
}
/*deletecarowner(){
    char name[20];
    printf("Enter the name of user to cancel the booking: ");
    fflush(stdin);
    gets(name);
    int flag=0;
     FILE* fp;
   fp=fopen("user.bin","rb+");
	struct User read;
	while(fread(&read,sizeof(struct User),1,fp)){
		if (strcmp(read.username,name)==0){
            printf("Deleting info....");
            read.cancel=1;
            flag=1;
            fseek(fp,-sizeof(struct User),SEEK_CUR);
            fwrite (&read, sizeof(struct User), 1, fp);
            break;
        }	
	}
    if (flag==1) {
        printf("Info deleted for User: ");
        puts(name);
    }

	fclose(fp);
}*/

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
