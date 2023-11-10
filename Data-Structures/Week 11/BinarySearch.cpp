#include<iostream>
using namespace std;
int main()
{
	int i,n,ele,a[10],low=0,high,mid,flag=1;
	cout<<"Enter n:";
	cin>>n;
	high=n-1;
	cout<<"\nEnter elements:";
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<"\nEnter element to be searched:";
	cin>>ele;
	do
	{
		mid=(low+high)/2;
		if(a[mid]==ele)
		{
			cout<<"\nElement found at "<<(mid+1);
			flag=0;
			break;			
		}
		else if(a[mid]>ele)
			high=mid-1;
		else if(a[mid]<ele)
			low=mid+1;
	}while(low<=high);
	if(flag==1)
		cout<<"\nElement not found!";
	return 0;
}