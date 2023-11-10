/*
	Week 3	16 Feb 2023
	Implementation of bubble sort
*/	
#include<iostream>
using namespace std;
void bubble(int arr[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(arr[j]>arr[j+1])
				swap(arr[j+1],arr[j]);
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
}
int main()
{
	int i,n,arr[10];
	cout<<"Enter number of elements:";
	cin>>n;
	cout<<"Enter elements:";
	for(i=0;i<n;i++)
		cin>>arr[i];
	bubble(arr,n);
}
