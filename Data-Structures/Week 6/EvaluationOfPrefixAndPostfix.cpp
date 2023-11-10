#include<iostream>
#include<sstream>
using namespace std;
int n,top=-1;
int str[100];
int convert(char s[80]) 
{ 
    int num=0; 
    for(int i=0;s[i]!='\0';i++) 
        num=num*10+(int(s[i])-48); 
    return num; 
} 
void push(int a)
{
    top=top+1;
    str[top]=a;
}
int pop()
{
    int a=str[top];
    top=top-1;
    return a;
}
char *reverse(char *exp)
{
	int len=0;
	char temp;
	for(int i=0;exp[i]!='\0';i++)
		len=len+1;
	int j=len-1;
	for(int i=0;i<(len/2);i++)
	{
		temp=exp[i];
		exp[i]=exp[j];
		exp[j]=temp;
		j--;
	}
	return exp;
}
int expEvaluation(char *exp,int isPrefix)
{
    int i,j,val,A,B,len=0;
    char ch,temp;
    for(i=0;exp[i]!='\0';i++)
    {
    	char temp_num[10];
    	ch=exp[i];
    	j=0;
    	if(ch!=' ' && ch>='0' && ch<='9')
    	{
    		while(ch!=' ')
    		{
    			temp_num[j]=ch;
    			i++;j++;
    			ch=exp[i];
			}
    		temp_num[j]='\0';
    		if(isPrefix)
    			push(convert(reverse(temp_num)));
    		else
				push(convert(temp_num));
		}
    	else if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
        {
    		A=pop();
        	B=pop();
      		switch(ch)
           	{
				case '*':
                val=B*A;
                break;

	            case '/':
    	        val=B/A;
        	    break;
			
			    case '+':
            	val=B+A;
            	break;

            	case '-':
            	val=B-A;
            	break;
            }
            push(val);
        }	
    }
    val=pop();
    return val;
}
int main()
{
	char exp[80];
	int pre,post;
	cout<<"Enter Prefix Expression:";
	cin.getline(exp,80);
	reverse(exp);
	pre=expEvaluation(exp,1);
	cout<<"Enter Postfix Expression:";
	cin.getline(exp,80);
	post=expEvaluation(exp,0);
	cout<<"Prefix result:"<<pre<<endl;
	cout<<"Postfix result:"<<post<<endl;
}
    