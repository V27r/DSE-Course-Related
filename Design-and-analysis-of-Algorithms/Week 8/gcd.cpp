#include<iostream>
using namespace std;
int main()
{
	cout<<"Enter two numbers:";
	int n,m,r;
	cin>>n>>m;
	while(n!=0)
	{
		r=m%n;
		m=n;
		n=r;
	}
	cout<<m;
}