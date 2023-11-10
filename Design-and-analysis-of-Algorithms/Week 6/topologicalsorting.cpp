#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAX 100

int n,adj[MAX][MAX],visited[MAX],stack[MAX],top=-1,indegree[MAX];

void push(int v) 
{
    if(top==MAX-1) 
        cout<<"\nStack Overflow!";
	else 
	{
        top=top+1;
        stack[top]=v;
    }
}
int pop() 
{
    int item;
    if(top==-1)
        cout<<"\nStack Underflow";
	else 
	{
        item=stack[top];
        top=top-1;
        return item;
    }
}
void create_graph() 
{
    int i,max_edges,origin,destin;
    cout<<"Enter number of vertices:";
    cin>>n;
    max_edges=n*(n-1);
    for(i=1;i<=max_edges;i++) 
	{
        cout<<"Enter edge "<<i<<" (-1 -1 to quit):";
        cin>>origin>>destin;
        if((origin==-1)&&(destin==-1))
            break;
        if(origin>=n || destin>=n || origin<0 || destin<0) 
		{
            cout<<"\nInvalid edge!";
            i--;
        } 
		else
		{
			indegree[destin]++;
            adj[origin][destin]=1;			
		}
    }
}
void dfs(int v) 
{
	int i;
	visited[v]=1;
	for(i=0;i<n;i++) 
		if(adj[v][i] && !visited[i])
			dfs(i);
	push(v);
}
void dfs_sort() 
{	
	int i;
	for(i=0;i<n;i++)
		visited[i]=0;
	for(i=0;i<n;i++)
		if(!visited[i])
			dfs(i);
	cout<<"\nTopological order using DFS:";
	while(top!=-1)
		cout<<pop()<<" ";
}
void source_removal()
{
	int node,top=-11,i,j,k=0,topo_order[MAX],queue[MAX];
	for(i=0;i<n;i++)
	    if(indegree[i]==0)
	        queue[++top]=i;
	while(top!=-11)
	{
	    node=queue[top--];
	    topo_order[++k]=node;
	    for(j=0;j<n;j++)
		{
	        if(adj[node][j]==true)
			{
	            indegree[j]--;
	            if(indegree[j]==0)
	                queue[++top]=j;
	        }
	    }   
	}
   cout<<"\n\nTopological Order using source removal:";
   for(i=1;i<=k;i++)
       cout<<topo_order[i]<<" ";
}
int main() 
{	
	create_graph();
	dfs_sort();
	source_removal();
	return 0;
}
