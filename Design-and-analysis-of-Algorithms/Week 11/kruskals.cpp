#include <bits/stdc++.h>
using namespace std;
#define V 6
#define Infinity 5000
int parent[V];
// Find set of vertex i
int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}
// Does union of i and j. It returns false if i and j are already in the same set.
void union1(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}
// Finds MST using Kruskal's algorithm
void kruskals(int cost[][V])
{
    int mincost = 0; // Cost of min MST.
    // Initialize sets of disjoint sets.
    for (int i = 0; i < V; i++)
        parent[i] = i;
    // Include minimum weight edges one by one
    int edge_count = 0;
    cout << "Edges Selected and corresponding cost:" << "\n";
    while (edge_count < V - 1) 
	{
        int min = Infinity, a = -1, b = -1;
        for (int i = 0; i < V; i++)
		{
            for (int j = 0; j < V; j++) 
			{
                if (find(i) != find(j) && cost[i][j] < min) 
				{
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        union1(a, b);
        cout << "(" << a+1 << ',' << b+1 << ")" << "\t\t" << min << "\n";
        edge_count++;
        mincost += min;
    }
    cout << "Minimum cost = " << mincost;
}

int main()
{
    int cost[][V] = {
        { Infinity, 6, 1, 5, Infinity, Infinity },
        { 6, Infinity, 5, Infinity, 3, Infinity },
        { 1, 5, Infinity, 5, 6, 4 },
        { 5, Infinity, 5, Infinity, Infinity, 2 },
        { Infinity, 3, 6, Infinity, Infinity, 6 },
        { Infinity, Infinity, 4, 2, 6, Infinity },
    };
    // Print the solution
    kruskals(cost);
    return 0;
}
