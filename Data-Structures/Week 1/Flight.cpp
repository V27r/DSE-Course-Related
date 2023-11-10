#include<iostream>
using namespace std;
class flight
{
	int flight_number;
	char destination[80];
	float distance;
	float fuel;
	void calculate_fuel()
	{
		if(distance<=1000)
			fuel=500;
		else if(distance>1000 && distance<=2000)
			fuel=1100;
		else
			fuel=2200;
	}
	public:
	void information_entry()
	{
		cout<<"Enter flight number:";
		cin>>flight_number;
		cout<<"Enter destination:";
		cin>>destination;
		cout<<"Enter distance:";
		cin>>distance;
		calculate_fuel();
	}
	void display_info()
	{	
		cout<<"Flight number:"<<flight_number;
		cout<<"\nDestination:"<<destination;
		cout<<"\nDistance:"<<distance;
		cout<<"\nFuel quantity:"<<fuel;
	}
};
int main()
{
	flight f;
	f.information_entry();
	f.display_info();
	return 0;
}