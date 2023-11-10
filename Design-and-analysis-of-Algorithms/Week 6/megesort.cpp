#include<iostream>
using namespace std;
void merge(int arr[],int left,int mid,int right) 
{
    int n1=mid-left+1;
    int n2=right-mid;
    int L[n1],M[n2];
    for (int i=0;i<n1;i++)
        L[i]=arr[left+i];
    for (int j=0;j<n2;j++)
        M[j]=arr[mid+1+j];
    int i=0,j=0,k=left;
    while(i<n1 && j<n2) 
	{
        if (L[i]<=M[j]) 
            arr[k++]=L[i++]; 
		else 
            arr[k++]=M[j++];
    }
    while(i<n1) 
        arr[k++]=L[i++];

    while(j<n2) 
        arr[k++]=M[j++];
}
void mergesort(int arr[],int left,int right)
{
	if(left<right)
	{
		int mid=(left+right)/2;
		mergesort(arr,left,mid);
		mergesort(arr,mid+1,right);
		merge(arr,left,mid,right);
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
	mergesort(arr,0,n-1);
	cout<<"Elements are sorting:";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}
