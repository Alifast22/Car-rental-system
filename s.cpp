#include<iostream>

using namespace std;


class add
{
	int num;
	int num1;
	int sum;
	public:
		
		add()
		{
			cout<<"Enter a number: ";
			cin>>num; 
			cout<<"Enter another number: ";
			cin>>num1; 
			sum=num+num1;	
		}
		
		void display()
		{
			cout<<"Sum of two numbers is: "<<sum;
		}
		
};
main()
{
	add a;
	a.display();
}
