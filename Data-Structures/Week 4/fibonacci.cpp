#include<iostream>
using namespace std;
int fib(int);
int main()
{
	int n,i;
	cout<<"Enter number of terms:";
	cin>>n;
	cout<<"Fibonacci terms:";
	for(i=0;i<n;i++)
		cout<<fib(i)<<" ";
	return 0;
}
int fib(int n)
{
	if(n==0 || n==1)
		return 1;
	else
		return fib(n-1)+fib(n-2);
}
