#include<iostream>
using namespace std;
int main()
{
	char word1[80],word2[80];
	cout<<"Enter first sentence:";
	cin.getline(word1,80);
	cout<<"Enter second sentence:";
	cin.getline(word2,80);
	int i=0,len1=0,len2=0;
	for(i=0;word1[i]!='\0';i++)
		len1=len1+1;
	for(i=0;word2[i]!='\0';i++)
		len2=len2+1;
	int j=len1;
	for(i=0;i<len2;i++)
	{
		word1[j]=word2[i];
		j++;
	}	
	word1[j]='\0';
	cout<<"After concatenating:"<<word1;
}
