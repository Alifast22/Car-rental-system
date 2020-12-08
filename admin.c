#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h> 
int login(){
    char adminemail[100],adminpass[100];
        printf("\t\t\t\t\tCar Rental System\n");
	printf("\t\t\t\t\t----------------\n");
	printf("\t\t\t\t\t      Login\n");
	printf("\t\t\t\t\t-----------------");

	printf("\n");
	sleep(2);
    int i,j;
     char *email[100]={"admin1","admin2","admin3"};
     char *pass[100]={"1","2","3"};
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
    system("cls");
   if (login()!=1){
       printf("\nAccess not granted :(");
       exit(0);
   }
    }
