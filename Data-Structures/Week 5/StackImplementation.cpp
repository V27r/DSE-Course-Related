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
bool isEmpty()
{
    return (top==-1);
}
bool isFull()
{
    if(top>=n-1)
        return false;
    else
        return true;
}
int main()
{
    int c,i;
    char a;
    cout<<"Enter number of elements:";
    cin>>n;
    do
    {
        cout<<"1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice:";
        cin>>c;
        switch(c)
        {
            case 1:
                if(isFull())
                {
                    cout<<"Enter an element:";
                    cin>>a;
                    push(a);
                    cout<<"\n";
                }
                else
                    cout<<"Stack is full!\n\n";
                break;
            
            case 2:
                if(!isEmpty())
                    cout<<"Element at the top:"<<pop()<<"\n\n";
                else
                    cout<<"Stack is empty!\n\n";
                break;
                
            case 3:
                if(!isEmpty())
                {
                    cout<<"Elements of stack:";
                    for(i=0;i<=top;i++)
                        cout<<str[i]<<" ";
                    cout<<"\n\n";
                }
                else
                    cout<<"Stack is empty!\n\n";
                break;
                
            case 4:
                cout<<"Exited!";
                exit(0);
                break;
            
            default:
                cout<<"Invalid input, try again!\n\n";
                break;
        }
    }while(c!=-1);
    return 0;
}