/*
	Week 3
	Implementation of selection sort
*/	
#include<iostream>
using namespace std;
void selection(int arr[],int n)
{
	int i,j,min,min_in;
	for(i=0;i<n-1;i++)
	{
		min_in=i;
		min=arr[i];
		for(j=i+1;j<n;j++)
			if(arr[j]<min)
			{
				min_in=j;
				min=arr[min_in];
			}				
		if(min_in!=i)
			swap(arr[min_in],arr[i]);
	}
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
	selection(arr,n);
}
