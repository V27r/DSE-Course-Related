#include<iostream>
using namespace std;
int main()
{
	char sen[80],del[80];
	int i,j=0,lensen,lendel,c,pos1,pos2;
	cout<<"Enter a sentence:";
	cin.getline(sen,80);
	cout<<"Enter word to be deleted:";
	cin>>del;
	for(i=0;sen[i]!='\0';i++)
		lensen=lensen+1;
	for(i=0;del[i]!='\0';i++)
		lendel=lendel+1;
	char news[80];
	for(i=0;i<lensen;i++)
	{
		j=0;
		c=0;
		pos1=i;
		if(sen[i]==del[j])
		{
			i++;
			j++;
			while(sen[i]==del[j])
			{
				i++;
				j++;
				c++;
			}
			if((c+1)==lendel)
			{
				pos2=pos1+lendel-1;
				break;
			}	
		}		
	}
	j=0;
	for(i=0;i<lensen;i++)
	{
		if(i>=pos1 && i<=pos2)
			continue;
		else
		{
			news[j]=sen[i];
			j++;
		}
	}
	cout<<"New sentence:"<<news;
	return 0;
}
