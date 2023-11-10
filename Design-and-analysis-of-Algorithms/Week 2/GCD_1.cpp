/* 
	Week 2
	Implementation of GCD using Euclid's algorithm
*/
#include<iostream>
using namespace std;
int GCD(int m,int n)
{
	if(m==0)
		return n;
	else if(n==0)
		return m;
	else 
		return GCD(n,m%n);
}
int main()
{
	int m,n;
	cout<<"Enter numbers to compute GCD using Euclid's Algorithm:";
	cin>>m>>n;
	cout<<"GCD of the two numbers:"<<GCD(m,n);
}
