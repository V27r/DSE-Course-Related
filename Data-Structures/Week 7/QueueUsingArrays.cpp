#include<iostream>
using namespace std;
#define size 5
int front=-1,rear=-1;
int queue[size];
void enQueue(int val)
{	
	if(front==-1)
		front=0;
	if(rear==size-1)
		cout<<"\nQueue is full!\n";
	else
	{
		rear=rear+1;
		queue[rear]=val;
		cout<<"\nElement inserted:"<<val<<endl;	
	}	
}
void deQueue()
{
	if(front==rear)
		cout<<"\nQueue is empty!\n";
	else
	{
		cout<<"\nDeleted element:"<<queue[front]<<endl;	
		front=front+1;
	}	
}
void display()
{
	if(front==rear)
		cout<<"\nQueue is empty!\n";
	else
	{
		cout<<"\nElements of queue:\n";
		for(int i=front;i<=rear;i++)
			cout<<queue[i]<<" ";
		cout<<"\n";
	}
}
int main()
{
	int val,choice;
	do
	{
		cout<<"1.Insert\n2.Delete\n3.Display\n4.Exit\n";
		cout<<"Enter your choice:";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"\nEnter value to be inserted:";
				cin>>val;
				enQueue(val);
				break;
				
			case 2:
				deQueue();
				break;
				
			case 3:
				display();
				break;
				
			case 4:
				cout<<"\nExited!";
				exit(0);
				break;
			
			default:
				cout<<"\nWrong choice!";
		}
	}while(1);
	return 0;
}
