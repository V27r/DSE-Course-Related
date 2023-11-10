/*
	Week 3
	Implementation of string matching by brute force technique
*/
#include<iostream>
using namespace std;
int len(char a[])
{
	int i=0;
	while(a[i]!='\0')
		i++;
	return i;
}
int match(char t[],char p[])
{
	int i,j,n=len(t),m=len(p);
	for(i=0;i<n-m+1;i++)
	{
		j=0;
		while(j<m && t[i+j]==p[j])
			j=j+1;
		if(j==m)
			return i;
	}
	return -1;
}
int main()
{
	char t[100],p[100];
	cout<<"Enter text:";
	cin.getline(t,100,'\n');
	cout<<"Enter pattern to be matched:";
	cin.getline(p,100,'\n');
	if(match(t,p)!=-1)
		cout<<"Match found at "<<match(t,p)<<"!";
	else
		cout<<"Match not found!";
}
