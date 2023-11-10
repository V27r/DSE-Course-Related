#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

void floyd(vector<vector<int>>& dist) 
{
    int n = dist.size();
    for (int k = 0; k < n; k++) 
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                if (dist[i][k] != INF && dist[k][j] != INF) 
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;
    vector<vector<int>> dist(n, vector<int>(n, INF));
    for (int i = 0; i < m; i++) 
	{
        int u, v, w;
        cout << "Enter edge " << i+1 << " and its weight: ";
        cin >> u >> v >> w;
        dist[u][v] = w;
    }
    for (int i = 0; i < n; i++) 
        dist[i][i] = 0;
    floyd(dist);
    cout << "The All-Pairs-Shortest-Paths distances are:\n";
    for (int i = 0; i < n; i++) 
	{
        for (int j = 0; j < n; j++) 
		{
            if (dist[i][j] == INF) 
                cout << "INF ";
            else 
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
