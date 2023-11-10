/* 
	Week 2
	Implementation of GCD using Middle school method
*/
#include<iostream>
using namespace std;
int GCD(int m,int n)
{
	int gcd=1;
	for(int i=2;i<=m && i<=n;i++)
		while(m%i==0 && n%i==0)
		{
			gcd*=i;
			m/=i;
			n/=i;
		}
	return gcd;
}
int main()
{
	int m,n;
	cout<<"Enter numbers to compute GCD using middle school algorithm:";
	cin>>m>>n;
	cout<<"GCD of two numbers:"<<GCD(m,n);
}
