#include<iostream>
using namespace std;
#define size 5
char *queue[size];
int front=-1,rear=-1,count=0;
void enQueue(char *val)
{	
	if((front==rear+1)||(front==0 && rear==size-1))
		cout<<"\nQueue is full!\n";
	else
	{
		if(front==-1)
			front=0;
		rear=(rear+1)%size;
		count++;
		queue[rear]=val;
		cout<<"\nElement inserted:"<<val<<endl;	
	}	
}
void deQueue()
{
	if(front==-1)
		cout<<"\nQueue is empty!\n";
	else
	{
		cout<<"\nDeleted element:"<<queue[front]<<endl;
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
			front=(front+1)%size;
	}	
}
void display()
{
	if(front==-1 && rear==-1)
		cout<<"\nQueue is empty!\n";
	else
	{
		cout<<"\nElements of queue:\n";
		for(int i=front;i<=count;i=(i+1)%size)
			cout<<queue[i]<<"\n";
		cout<<"\n";
	}
}
int main()
{
	char val[10];
	int choice;
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
