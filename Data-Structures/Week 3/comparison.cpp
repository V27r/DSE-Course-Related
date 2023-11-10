#include<iostream>
using namespace std;
int main()
{
	char word1[80],word2[80];
	cout<<"Enter first word:";
	cin>>word1;
	cout<<"Enter second word:";
	cin>>word2;
	int i=0,len1=0,len2=0,count=0;
	for(i=0;word1[i]!='\0';i++)
		len1=len1+1;
	for(i=0;word2[i]!='\0';i++)
		len2=len2+1;
	if(len1!=len2)
		cout<<"Words are different!";
	else
	{
		for(i=0;i<len1;i++)
		{
			if(word1[i]==word2[i])
				count=count+1;
			else
			{
				cout<<"Words are not same!";
				return 0;
			}
		}
		if(count==len1)
			cout<<"Words are same!";
	}
	return 0;
}
