#include<iostream>
using namespace std;
int fact(int i)
{
	if(i==1)
		return 1;
	else 
		return i*fact(i-1);
}
int main()
{
	int n;
	cout<<"Enter number:";
	cin>>n;
	cout<<"Factorial of "<<n<<":"<<fact(n);
	return 0;
}