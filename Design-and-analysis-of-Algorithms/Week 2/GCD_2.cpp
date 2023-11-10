/* 
	Week 2
	Implementation of GCD using Consecutive integer checking algorithm
*/
#include<iostream>
using namespace std;
int GCD(int m,int n,int r)
{
	if(m%r==0 && n%r==0)
		return r;
	return GCD(m,n,r-1);
}
int main()
{
	int m,n;
	cout<<"Enter number to compute GCD using Consecutive integer checking algorithm:";
	cin>>m>>n;
	cout<<"GCD of two numbers:"<<GCD(m,n,min(m,n));
}