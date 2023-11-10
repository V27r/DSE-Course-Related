#include<iostream>
using namespace std;
int count=-1;
struct node
{
    int data;
    node *next;
};
struct node *head=NULL;
void insert()
{
	int data;
	if(count==-1)
	{
		struct node *newNode=new struct node; 
		newNode->data=(int)NULL;
		newNode->next=head;
		head=newNode;
	}
	cout<<"\nEnter element to be inserted in the queue:";
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
void del()
{
	int del;
	if(count==-1)
		cout<<"\nQueue is empty!\n";
	else
	{
		struct node *temp=head;
		del=temp->data;
    	head=head->next;
		free(temp);
		cout<<"\nElement "<<del<<" deleted!\n";
	}		
}
void print()
{
	if(count==-1)
		cout<<"\nQueue is empty!\n";
	else
	{
		cout<<"\nElements of the queue:\n";
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
		cout<<"\n1.Insert an element in the queue";
		cout<<"\n2.Delete an element from the queue";
		cout<<"\n3.Print the queue";
		cout<<"\n4.Exit";
		cout<<"\nEnter your choice:";
		cin>>choice;
		switch(choice)
		{
			case 1:
				insert();
				break;
				
			case 2:
				del();
				break;
				
			case 3:
				print();
				break;

			case 4:
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