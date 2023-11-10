#include<iostream>
using namespace std;
int main()
{
	int a[10],n,i=0,ele,flag=1;
	cout<<"Enter n:";
	cin>>n;
	cout<<"\nEnter elements:";
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<"\nEnter element to be searched:";
	cin>>ele;		
	for(i=0;i<n;i++)
		if(a[i]==ele)
		{
			cout<<"\nElement found at "<<(i+1);
			flag=0;
			break;			
		}
	if(flag==1)
		cout<<"\nElement not found!";
	return 0;
}