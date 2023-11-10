#include<iostream>
using namespace std;
int top=-1;
char str[100];
int n;
bool isEmpty()
{
    if(top==-1)
        return true;
    else
        return false;
}
void push(char a)
{
    top=top+1;
    str[top]=a;
}
char peek()
{
    return str[top];
}
char pop()
{
    char a=str[top];
    top=top-1;
    return a;
}
bool isFull()
{
    if(top>=n-1)
        return false;
    else
        return true;
}
int precedence(char c)
{
    if(c=='^')
        return 3;
    else if(c=='/'||c=='*')
        return 2;
    else if(c=='+'||c=='-')
        return 1;
    else
        return -1;
}
int check(char exp[100])
{
    char x;
    int i;
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
                    return 0;
            }
            else
                return 0;      
        }
    }
    if(top==-1)
        return 1;
    else
        return 0;
}
int main()
{
    char exp[100];
    char postfix[100]="";
    char prefix[100]="";
    char x;
    int i,j=0,len=0;
    cout<<"Enter an expression:";
    cin>>exp;
    if(check(exp)==1)
    {
        for(i=0;exp[i]!='\0';i++)
        {
            len=len+1;
            char c = exp[i];
            if ((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9'))
            {
                postfix[j]+= c;
                j++;
            }    
            else if (c == '(')
                push('(');
               else if (c == ')')
            {
                while(peek()!='(')
                {
                    postfix[j]+=peek();
                    x=pop();
                    j++;
                }
                x=pop();
            }
            else
            {
                while(!isEmpty() && precedence(exp[i])<=precedence(peek()))
                {
                    postfix[j]+=peek();
                    x=pop();
                    j++;
                }
                push(c);
            }
        }
        while(!isEmpty())
        {
            postfix[j]+=peek();
            j++;
            x=pop();
        }
        cout<<"Postfix Expression:"<<postfix<<endl;
        j=0;
        for(i=len-1;i>=0;i--)
        {
            char c=exp[i];
            if ((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9'))
            {
                prefix[j]+= c;
                j++;
            }    
            else if (c==')')
                push(')');
               else if (c=='(')
            {
                while(peek()!=')')
                {
                    prefix[j]+=peek();
                    x=pop();
                    j++;
                }
                x=pop();
            }
            else
            {
                while(!isEmpty() && precedence(exp[i])<=precedence(peek()))
                {
                    prefix[j]+=peek();
                    x=pop();
                    j++;
                }
                push(c);
            }    
        }
        while(!isEmpty())
        {
            prefix[j]+=peek();
            j++;
            x=pop();
        }
        cout<<"Prefix Expression:";
        for(i=len-1;i>=0;i--)
            cout<<prefix[i];
    }
    else
        cout<<"Wrong Expression!";
    return 0;
}