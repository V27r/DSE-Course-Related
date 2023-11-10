#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
const int MAX_VERTICES = 100;
int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int pushOrder[MAX_VERTICES], popOrder[MAX_VERTICES];
int pushIndex = 0, popIndex = 0;
void dfs(int v) 
{
    visited[v] = true;
    pushOrder[pushIndex++] = v;
    for (int i = 0; i < MAX_VERTICES; i++) 
        if (graph[v][i] && !visited[i])
            dfs(i);
    popOrder[popIndex++] = v;
}
int main() {
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
        cin>> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }
    cout << "DFS Traversal: ";
    for (int i = 0; i < V; i++) 
        if (!visited[i]) 
            dfs(i);
    cout << endl;
    cout << "Push order: ";
    for (int i = 0; i < V; i++)
        cout << pushOrder[i] << " ";
    cout << endl;
    cout << "Pop order: ";
    for (int i = 0; i < V; i++)
        cout << popOrder[i] << " ";
    cout << endl;
    return 0;
}