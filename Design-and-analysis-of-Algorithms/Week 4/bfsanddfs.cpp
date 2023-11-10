#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MAX_VERTICES = 100;

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

void dfs(int v) 
{
    visited[v] = true;
    cout << v << " ";
    for (int i = 0; i < MAX_VERTICES; i++) 
        if (graph[v][i] && !visited[i]) 
            dfs(i);
}
void bfs(int v) 
{
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while (!q.empty()) 
	{
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        for (int i = 0; i < MAX_VERTICES; i++) 
		{
			int next=graph[curr][i];
            if (!visited[next]) 
			{
				visited[next] = true;
                q.push(next);
            }
        }
    }
}
int main() 
{
    memset(graph, 0, sizeof(graph));
    memset(visited, 0, sizeof(visited));
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < E; i++) 
	{
        int u, v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }
    cout << "DFS Traversal: ";
    for (int i = 0; i < V; i++) 
        if (!visited[i]) 
            dfs(i);
    cout << endl;
    memset(visited, 0, sizeof(visited));
    cout << "BFS Traversal: ";
    for (int i = 0; i < V; i++) 
        if (!visited[i]) 
            bfs(i);
    return 0;
}
