#include<iostream>
using namespace std;
class EMPLOYEE
{
	int Employee_Number;
	char Employee_Name[80];
	int basic;
	int DA;
	int IT;
	int Net_Sal;
	int Gross_Sal;
	public:
	void read_data()
	{
		cout<<"Enter employee number:";
		cin>>Employee_Number;
		cout<<"Enter employee name:";
		cin>>Employee_Name;
		cout<<"Enter basic salary:";
		cin>>basic;
		cout<<"Enter DA:";
		cin>>DA;
		cout<<"Enter IT:";
		cin>>IT;
	}
	void calnet()
	{
		Net_Sal=basic+DA;
	}
	void calgross()
	{
		Gross_Sal=Net_Sal-IT;
	}
	void display()
	{	
		cout<<"\nName of Employee:"<<Employee_Name<<" "<<Employee_Number;
		cout<<"\nNet Salary:"<<Net_Sal;
		cout<<"\nGross Salary:"<<Gross_Sal;
	}
};
int main()
{
	int n,i;
	cout<<"Enter number of employees:";
	cin>>n;
	EMPLOYEE s[n];
	for(i=0;i<n;i++)
	{
		s[i].read_data();
		s[i].calnet();
		s[i].calgross();
	}
	for(i=0;i<n;i++)
	{
		s[i].display();
		cout<<"\n";
	}
	return 0;
}