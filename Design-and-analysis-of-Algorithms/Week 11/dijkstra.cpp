#include <iostream>
#define MAX_N 100
#define INF 1e9
using namespace std;
int graph[MAX_N][MAX_N]; // adjacency matrix representation of the graph
int dist[MAX_N]; // array to store the minimum distances
bool visited[MAX_N]; // array to keep track of visited vertices

void dijkstra(int start_vertex, int n) 
{
    for (int i = 0; i < n; i++) 
	{
        dist[i] = INF;
        visited[i] = false;
    }
    dist[start_vertex] = 0;
    for (int i = 0; i < n; i++)
	{
        // find the unvisited vertex with minimum distance
        int u = -1;
        for (int j = 0; j < n; j++)
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) 
                u = j;//finding the shortest path from the vertex to any of the next vertex
        if (dist[u] == INF) break;
            // all remaining vertices are inaccessible from the start vertex 
        visited[u] = true;
        // update the distances of the unvisited neighbors of u
        for (int v = 0; v < n; v++) 
		{
            if (graph[u][v] != 0) 
			{
                int w = graph[u][v];
                if (dist[u] + w < dist[v]) 
                    dist[v] = dist[u] + w;
            }
        }
    }
}

int main() 
{
    int n, m, start_vertex;
    cout<<"Enter number of vertices, number of edges and start index:";
    cin >> n >> m >> start_vertex;
    // initialize the graph with zeros
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            graph[i][j] = 0;
    // read the edges and weights from input and update the graph
    for (int i = 0; i < m; i++)
	{
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }
    dijkstra(start_vertex, n);
    // print the shortest paths
    for (int i = 0; i < n; i++)
        cout << "Shortest path from " << start_vertex << " to " << i << " is " << dist[i] << endl;
    return 0;
}