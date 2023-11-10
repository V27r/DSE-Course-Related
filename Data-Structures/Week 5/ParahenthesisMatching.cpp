#include<iostream>
#include<stdlib.h>
using namespace std;
int top=-1;
char str[100];
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
bool isEmpty()
{
    return (top==-1);
}
int main()
{
    char exp[100],x;
    int i;
    cout<<"Enter an expression:";
    gets(exp);
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='[' || exp[i]=='{' || exp[i]=='(')
            push(exp[i]);
        if(exp[i]==']' || exp[i]=='}' || exp[i]==')')
        {
            if(!isEmpty())
            {
                x=pop();
                if(x=='(' && exp[i]==')')
                    continue;
                else if(x=='[' && exp[i]==']')
                    continue;
                else if(x=='{' && exp[i]=='}')
                    continue;
                else
                {
                    cout<<"Invalid Expression!";
                    exit(0);
                }    
            }
            else
            {
                cout<<"Invalid Expression!";
                exit(0);
            }        
        }
    }
    if(top==-1)
        cout<<"Right Expression!";
    else
        cout<<"Invalid Expression!";
    return 0;
}