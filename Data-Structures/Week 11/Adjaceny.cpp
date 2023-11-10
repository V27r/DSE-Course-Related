#include<iostream>
#include<vector>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printGraph(vector<int> adj[], int V)
{
    for(int i=0;i<V;i++) 
	{
        cout<<"\nAdjacency list of vertex " <<i<<"\nhead ";
        for(auto x:adj[i])
            cout<< "->"<<x;
        cout<<"\n";
    }
}
int main()
{
	int n,m,i,j;
	cout<<"Enter number of vertices and edges:";
	cin>>n>>m;	
	int adjMat[n+1][n+1];
	for (int i=0;i<m;i++) 
	{
		int u,v;
		cout<<"\nEnter u and v:";
		cin>>u>>v;
		adjMat[u][v]=1;
		adjMat[v][u]=1;
	}
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<n+1;j++)
			if(adjMat[i][j]!=1)
				adjMat[i][j]=0;
	}
	cout<<"\nAdjaceny Matrix\n\n";
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<n+1;j++)
			cout<<adjMat[i][j]<<"  ";
		cout<<"\n";		
	}
	cout<<"\nAdjaceny List:\n";	
	int V=5;
    vector<int> adj[V];
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    printGraph(adj, V);
    return 0;
}