#include<iostream>
using namespace std;
int partition(int arr[],int left,int right)
{
	int pivot=arr[left];
	int i=left+1,j=right;
	while(true)
	{
		while(pivot>=arr[i] && i<=right) i++;
		while(pivot<arr[j]) j--;
		if(i<j)
			swap(arr[i],arr[j]);
		else
		{
			swap(arr[left],arr[j]);
			return j;			
		}
	}
}
int quicksort(int arr[],int left,int right)
{
	if(left<right)
	{
		int pivot=partition(arr,left,right);
		quicksort(arr,left,pivot-1);
		quicksort(arr,pivot+1,right);
	}
}
int main()
{
	int i,n,arr[10];
	cout<<"Enter number of elements:";
	cin>>n;
	cout<<"Enter elements:";
	for(i=0;i<n;i++)
		cin>>arr[i];
	quicksort(arr,0,n-1);
	cout<<"Elements are sorting:";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}
