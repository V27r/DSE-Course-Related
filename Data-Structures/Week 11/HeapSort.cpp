#include <iostream>
using namespace std;
void heapify(int arr[], int N, int i)
{
	int largest=i;	
	int l=2*i+1;
	int r=2*i+2;
	if(l<N && arr[l]>arr[largest])
		largest=l;
	if(r<N && arr[r]>arr[largest])
		largest=r;
	if(largest!=i) 
	{
		swap(arr[i],arr[largest]);
		heapify(arr,N,largest);
	}
}
void heapSort(int arr[], int n)
{
	for (int i=n/2-1;i>=0;i--)
		heapify(arr,n,i);
	for (int i=n-1;i>0;i--) 
	{
		swap(arr[0],arr[i]);
		heapify(arr,i,0);
	}
}
void printArray(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout << "\n";
}
int main()
{
	int n,arr[10],i;
	cout<<"\nEnter n:";
	cin>>n;
	cout<<"\nEnter elements:";
	for(i=0;i<n;i++)
		cin>>arr[i];
	heapSort(arr,n);
	cout<<"Sorted array:\n";
	printArray(arr,n);
}
