#include "../bits/stdc++.h"

using namespace std;

#define N 10

struct Edge {
    int src, dest;
};

// class to represent the graph as a adjacency list
class Graph
{
    public:
        // A array of vectors to represent adjacency list
        vector<int> adjList[N];
        
        // Constructor
        
        Graph(vector<Edge> edges)
        {
            // add edges to the undirected graphs
            for (int i =0; i < edges.size(); i++)
            {
                int src = edges[i].src;
                int dest = edges[i].dest;

                adjList[src].push_back(dest);
                adjList[dest].push_back(src);
            }
        }
};


bool DFS(Graph const &graph, int v, vector<bool> &discovered, vector<int> &color)
{
    // do for every edge (v -> u)
    for (int u : graph.adjList[v])
    {
        // if vertex u is explored for first time
        if (discovered[u] == false)
        {
            // mark current node as discovered
            discovered[u] = true;

            // set color as oposite color of parent node
            color[u] = !color[v];

            // if DFS on any subtree rooted at v
            // we return false
            if (DFS(graph, u, discovered, color) == false) {
                return false;
            }
        }
        // if the vertex is already been discovered and color of ver
        // u and v are the same, then the graph is not bipartite
        
        else if (color[v] == color[u])
            return false;
    }
    return true;
}

int main()
{
    // adjacency list representation of it
    vector<Edge> edges {{1,2}, {2,3}, {2,8}, {3,4}, {4,6}, {5,7}, {5,9}, {8,9}, {2,4}};

    Graph graph(edges);

    vector<bool> discovered(N);

    vector<int> color(N);

    // mark source vertex as discovered and
    // set its color to 0
    
    discovered[0] = true, color[0] = 0;

    // start DFS traversal from any node as graph
    // is connected and undirected
    if (DFS(graph, 1, discovered, color))
        cout << "Bipartite graph" << endl;
    else
        cout << "Not a bipartitie graph" << endl;
    return  0;
}
