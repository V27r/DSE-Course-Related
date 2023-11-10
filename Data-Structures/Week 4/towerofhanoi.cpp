#include<iostream>
#include<math.h>
using namespace std;
int toh(int,char,char,char);
int main()
{
	int n,a;
	cout<<"Enter number of disks:";
	cin>>n;
	cout<<"Total number of moves:"<<(pow(2,n)-1)<<"\n";
	a=toh(n,'A','C','B');
	cout<<a;
	return 0;
}
int toh(int n,char from,char to,char aux)
{
	if(n==1)
	{
		cout<<"Move disk 1 from "<<from<<" to "<<to<<"."<<"\n";
		return 0;
	}
	toh(n-1,from,aux,to);
	cout<<"Move disk "<<n<<" from "<<from<<" to "<<to<<"."<<"\n";
	toh(n-1,aux,to,from);
}
