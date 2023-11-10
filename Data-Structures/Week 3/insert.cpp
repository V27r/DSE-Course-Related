#include<iostream>
using namespace std;
int main()
{
	char word[80];
	char ins[80];
	char newer[80]="";
	int pos,j;
	cout<<"Enter a sentence:";
	cin.getline(word,80);
	cout<<"Enter a word to be inserted:";
	cin>>ins;
	cout<<"Enter position:";
	cin>>pos;
	int i,len1=0,len2=0,len3=0;
	for(i=0;word[i]!='\0';i++)
		len1=len1+1;
	for(i=0;ins[i]!='\0';i++)
		len2=len2+1;
	for(i=0;i<pos;i++)
		newer[i]=word[i];
	for(i=pos;i<(len2+pos);i++)
		newer[i]=ins[i-pos];
	newer[i]=' ';
	for(i=0;newer[i]!='\0';i++)
		len3=len3+1;
	j=0;
	for(i=pos;i<len1;i++)
	{
		newer[j+len3]=word[i];
		j++;
	}
	cout<<"New sentence:"<<newer;
	return 0;
}
