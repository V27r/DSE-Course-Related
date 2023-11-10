#include<iostream>
#include<stdlib.h>
using namespace std;
int top=-1;
char str[100];
int n;
void push(char a)
{
    top=top+1;
    str[top]=a;
}
char pop()
{
    char a=str[top];
    top=top-1;
    return a;
}
int main()
{
    char sen[100],x;
    int lensen=0,i=0,count=0;
    cout<<"Enter a string:";
    gets(sen);
    for(i=0;sen[i]!='\0';i++)
    {
        lensen=lensen+1;
        push(sen[i]);
    }
    for(i=0;sen[i]!='\0';i++)
    {
        x=pop();
        if(sen[i]==x)
            count=count+1;
        else
        {
            cout<<"String is not palindrome!";
            exit(0);
        }
    }
    if(count==lensen)
        cout<<"String is palindrome!";
    else
        cout<<"String is not palindrome!";
    return 0;
}