#include "bits/stdc++.h"
using namespace std;

#define pb push_back

void addEdge(int u, int v, vector<int> adj[])
{
    adj[u].pb(v), adj[v].pb(u);
}

bool checkCycle(int node, vector<int> adj[], int vis[], int dfsVis[])
{
    vis[node] = 1, dfsVis[node] = 1;
    for (auto it: adj[node])
    {
        if (!vis[it])
        {
            if (checkCycle(it, adj, vis, dfsVis))   return true;
        }
        else if (dfsVis[it])
        {
            return true;
        }
    }
    dfsVis[node] = 0;
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    int vis[V] = {0}, dfsVis[V] = {0};
    for (int i = 0; i < V; ++i)
    {
        if (!vis[i])
        {
            if (checkCycle(i, adj, vis, dfsVis))    return true;
        }
    }

    return false;
}

int main()
{
    int V = 6;
    vector<int> adj[V];
    addEdge(0, 1, adj);
    addEdge(1, 2, adj);
    addEdge(1, 5, adj);
    addEdge(2, 3, adj);
    addEdge(3, 4, adj);
    addEdge(4, 0, adj);
    addEdge(4, 1, adj);

    if (isCycle(V, adj))
    {
        cout << "Cycle" << endl;
    }
    else
    {
        cout << "Not Cycle" << endl;
    }

    for (int i = 0; i < V; ++i) adj[i].clear();

    return 0;
}