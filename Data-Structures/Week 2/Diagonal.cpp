#include<iostream>
using namespace std;
int main()
{
int i,j=0,n,k=0,f=0;
int a[100][100],b[100];
cout<<"Enter order of matrix:";
cin>>n;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
{
cout<<"Enter value at "<<i<<","<<j<<":";
cin>>a[i][j];
}
cout<<"\n2-D array:\n";
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
cout<<a[i][j]<<" ";
cout<<"\n";
}
cout<<"\n1-D array:\n";
j=0;
for(i=0;i<n;i++)
{
b[j]=a[i][i];
j++;
}
for(i=0;i<j;i++)
cout<<b[i]<<" ";
cout<<"\nEnter position of the element in 2-D array:";
cin>>i>>j;
k=i;
cout<<"Position of the element in 1-D array:"<<k;
}