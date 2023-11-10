/*
    Implementation of Graph using Adjacency Matrix and Adjacency List
     02 Feb 2023
*/
#include<iostream>
#include<vector>
using namespace std;
void mat()
{
	int ver,u,v;
    char val='y';
    cout<<"Enter number of vertices:";
    cin>>ver;
    int arr[ver][ver];
    while(val!='n')
    {
        cout<<"Enter edge pair (u,v):";
        cin>>u>>v;
        arr[u][v]=1;
        cout<<"Do you want to enter more values(y/n)?";
        cin>>val;
    }
    for(int i=0;i<ver;i++)
    {
        for(int j=0;j<ver;j++)
            if(arr[i][j]!=1)
                arr[i][j]=0;
    }
    cout<<"Adjacency Matrix:\n";
    for(int i=0;i<ver;i++)
    {
        for(int j=0;j<ver;j++)  
             cout<<arr[i][j]<<" ";
        cout<<"\n";
    }
}
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void printGraph(vector<int> adj[], int V)
{
	for (int v=0;v<V;v++) 
	{
		cout<<"\nAdjacency list of vertex "<<v<<"\n head ";
		for (auto x : adj[v])
			cout << "-> " << x;
		printf("\n");
	}
}
void list()
{
	int V,i,j,k,val;
	cout<<"\nEnter number of vertices:";
	cin>>V;
	vector<int> adj[V];
	for(i=0;i<V;i++)
	{
		cout<<"Enter number of vertices adjacent to vertex "<<i<<":";
		cin>>k;
		cout<<"Enter values:";
		for(j=0;j<k;j++)
		{
			cin>>val;
			addEdge(adj,i,val);			
		}
	}
	printGraph(adj, V);
}
int main()
{
	int choice;
	do
	{
		cout<<"1.Adjacency Matrix\n";
		cout<<"2.Adjacency List\n";
		cout<<"3.Exit\n";
		cout<<"Enter your choice:";
		cin>>choice;
		switch(choice)
		{
			case 1:
				mat();
				break;
			
			case 2:
				list();
				break;
				
			case 3:
				cout<<"Exited!\n";
				break;
				
			default:
				cout<<"Invalid choice!\n";		
		}
	}while(choice!=3);
     return 0;
}