#include<iostream>
using namespace std;
int count=-1;
struct node
{
    int data;
    node *next;
};
struct node *head=NULL;
void insertbegin()
{
	int data;
	if(count==-1)
	{
		struct node *newNode=new struct node; 
		newNode->data=(int)NULL;
		newNode->next=head;
		head=newNode;
	}
	cout<<"\nEnter element to be inserted at the start of the list:";
	cin>>data;
	struct node *newNode=new struct node; 
	newNode->data=data;
	newNode->next=head;
	head=newNode;
	count++;	
	cout<<"\nElement "<<data<<" inserted!\n";
}
void insertend()
{
	int data;
	if(count==-1)
	{
		struct node *newNode=new struct node; 
		newNode->data=(int)NULL;
		newNode->next=head;
		head=newNode;
	}
	cout<<"\nEnter element to be inserted at the end of the list:";
	cin>>data;
	struct node *newNode=new struct node;
	newNode->data=data;
	newNode->next=NULL;
	struct node *temp=head; 
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=newNode; 
	temp->data=data;
	count++;
	cout<<"\nElement "<<data<<" inserted!\n";
}
void insbefore()
{
	int data,bef,flag=0;
	if(count!=-1)
	{
		cout<<"\nEnter element to be inserted:";
		cin>>data;
		cout<<"\nEnter element before which element is to be inserted:";
		cin>>bef;
		struct node *temp=head; 
		struct node *temp2=temp->next;
		do
		{
			if(temp->data==bef)
			{
				struct node *newNode=new struct node; 
				newNode->data=data;
				newNode->next=head;
				head=newNode;
				count++;	
				cout<<"\nElement "<<data<<" inserted!\n";
				flag=1;
				break;
			}
			if(temp2->data==bef)
			{
				struct node *newNode=new struct node; 
				newNode->data=data;
				newNode->next=temp->next;
				temp->next=newNode; 
				count++;
				cout<<"\nElement "<<data<<" inserted!\n";
				flag=1;
				break;		
			}
			temp=temp->next;
			temp2=temp->next;
		}while(temp2->next!=NULL);
		if(flag==0)
			cout<<"\nElement not found in the list!\n";
	}	
	else
		cout<<"\nList is empty!\n";	
}
void insafter()
{
	int data,aft,flag=0;
	if(count!=-1)
	{
		cout<<"\nEnter element to be inserted:";
		cin>>data;
		cout<<"\nEnter element after which element is to be inserted:";
		cin>>aft;
		struct node *temp=head; 
		struct node *pos;
		do
		{
			if(temp->data==aft)
			{
				struct node *newNode=new struct node; 
				newNode->data=data;
				newNode->next=temp->next;
				temp->next=newNode; 
				count++;
				cout<<"\nElement "<<data<<" inserted!\n";
				flag=1;
				break;		
			}
			temp=temp->next;
		}while(temp->next!=NULL);
		if(flag==0)
			cout<<"\nElement not found in the list!\n";
	}	
	else
		cout<<"\nList is empty!\n";	
}
void del()
{
	int del,flag=0;
	if(count==-1)
		cout<<"\nList is empty!\n";
	else
	{
		cout<<"\nEnter element to be deleted:";
		cin>>del;
		struct node *temp=head;
		struct node* prev=NULL;
		if(temp!=NULL && temp->data==del) 
		{
        		head=temp->next;
        		cout<<"\nElement "<<del<<" deleted!\n";
        		flag=1;
        		delete temp;
    		}
		else
		{
        		while(temp!=NULL && temp->data!=del) 
				{
            		prev=temp;
            		temp=temp->next;
            		flag=1;
        		}
        		prev->next=temp->next;
        		cout<<"\nElement "<<del<<" deleted!\n";
        		delete temp;
    		}
		if(flag==0)
			cout<<"\nElement not found in the list!\n";
	}		
}
void print()
{
	if(count==-1)
		cout<<"\nList is empty!\n";
	else
	{
		cout<<"\nElements of linked list:\n";
		struct node *temp=head; 
		if(count!=-1)
		{
			do
			{
				cout<<temp->data<<"->";
				temp=temp->next;
			}while(temp->next!=NULL);
		}		
		cout<<"NULL";
		cout<<"\n";
	}
}
int main()
{
	int choice;
	do
	{
		cout<<"\n1.Insert an element in the beginning of the list";
		cout<<"\n2.Insert an element at the end of the list";
		cout<<"\n3.Insert an element before another element in the existing list";
		cout<<"\n4.Insert an element after another element in the existing list";
		cout<<"\n5.Delete a given element from the list";
		cout<<"\n6.Print the list";
		cout<<"\n7.Exit";
		cout<<"\nEnter your choice:";
		cin>>choice;
		switch(choice)
		{
			case 1:
				insertbegin();
				break;
				
			case 2:
				insertend();
				break;
				
			case 3:
				insbefore();
				break;

			case 4:
				insafter();
				break;
			
			case 5:
				del();
				break;
				
			case 6:
				print();
				break;
				
			case 7:
				cout<<"\nExited!";
				exit(0);
				break;
				
			default:
				cout<<"\nInvalid input, try again!\n";
				break;
		}
	}while(1);
	return 0;
}
