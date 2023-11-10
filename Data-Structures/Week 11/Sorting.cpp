#include <iostream>
using namespace std;
void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}
void printArray(int arr[],int size)
{
	int i;
	for(i=0;i<size;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
void BubbleSort(int arr[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(arr[j]>arr[j+1])
				swap(arr[j],arr[j+1]);
	printArray(arr,n);
}
int partition(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++) 
	{
        if (arr[j]<pivot) 
		{
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}
void QuickSort(int arr[],int low,int high)
{
    if(low<high) 
	{
        int pi=partition(arr,low,high);
        QuickSort(arr,low,pi-1);
        QuickSort(arr,pi+1,high);
    }
}
void SelectionSort(int arr[], int n)
{
    int i,j,min_idx;
    for(i=0;i<n-1;i++)
    {
        min_idx=i;
        for(j=i+1;j<n;j++)
        	if(arr[j]<arr[min_idx])
            	min_idx=j;
        if(min_idx!=i)
            swap(&arr[min_idx],&arr[i]);
    }
    printArray(arr,n);
}
void InsertionSort(int arr[],int n)
{
    int i,key,j;
    for(i=1;i<n;i++)
    {
        key=arr[i];
		j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
    printArray(arr,n);
}
int main()
{
	int arr[10],i,n,choice;
	cout<<"\nEnter n:";
	cin>>n;
	cout<<"\nEnter elements:";
	for(i=0;i<n;i++)
		cin>>arr[i];
	do
	{
		cout<<"\n1.Bubble sort \n2.Quick sort \n3.Selection sort \n4.Insertion sort\n5.Exit\n";
		cout<<"Enter your choice:";
		cin>>choice;
		switch(choice)
		{
			case 1:
				BubbleSort(arr,n);
				break;
			
			case 2:
				QuickSort(arr,0,n-1);
				printArray(arr,n);
				break;
				
			case 3:
				SelectionSort(arr,n);
				break;
				
			case 4:
				InsertionSort(arr,n);
				break;
				
			case 5:
				cout<<"\nExited!";
				exit(0);
				
			default:
				cout<<"\nInvalid choice!\n";
		}
	}while(1);
	return 0;
}
