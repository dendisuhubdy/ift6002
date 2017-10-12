#include "../bits/stdc++.h"


using namespace std;

#define V 4

// this function returns true if graph G[V][V] is bipartite
// else false
//
bool isBipartiteUtil(int G[][V], int src, int colorArr[])
{
    colorArr[src] = 1;

    // Create a queue (FIFO) of vertex numbers and enqueue
    // source vertex for BFS traversal
    //
    queue <int> q;
    q.push(src);

    while (!q.empty())
    {
        // dequeue a vertex from queue
        int u = q.front();
        q.pop();

        // return false if there is a self-loop
        if (G[u][u] == 1)
            return false;

        // Find all non-colored adjacent vertices
        for (int v = 0; v <V; ++v) {
            // An edge from u to v exists and
            // destination v is not colored
            if (G[u][v] && colorArr[v] == -1)
            {
                // Assign alternate color to this
                // adjacent v of u
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }

            else if(G[u][v] && colorArr[v] == colorArr[u])
                return false;
        }
    }
    return true;
}

bool isBipartite(int G[][V])
{
    // Time Complexity of the above approach is same as that Breadth First Search. 
    // In above implementation is O(V^2) where V is number of vertices. 
    // If graph is represented using adjacency list, then the complexity becomes O(V+E).
    int colorArr[V];
    for (int i = 0; i < V; ++i)
        colorArr[i] = -1;

    // This code is to handle disconnected graph
    for (int i = 0; i<V; i++) {
        if(colorArr[i] == -1) {
            if (isBipartiteUtil(G, i, colorArr) == false)
                return false;
        }
    }
    return true;
}

int main()
{
    int G[][V] = {{0, 1, 0, 1},
                    {1,0,1,0},
                    {0,1,0,1},
                    {1,0,1,0}
    };

    isBipartite(G) ? cout << "Yes" : cout << "No";

    return 0;
}
