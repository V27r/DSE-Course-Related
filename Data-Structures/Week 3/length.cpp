#include<iostream>
using namespace std;
int main()
{
	char word[80];
	cout<<"Enter a word:";
	scanf("%s",word);
	int i,count=0;
	for(i=0;word[i]!='\0';i++)
		count=count+1;
	cout<<"Length of word is:"<<count;
	return 0;
}
