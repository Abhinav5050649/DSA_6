#include "bits/stdc++.h"
using namespace std;

#define pb push_back

//Topo Sort Using DFS
void addEdge(int u, int v, vector<int> adj[])
{
    adj[u].pb(v), adj[v].pb(u);
}

void findTopoSort(int node, vector<int> &vis, stack<int> &s, vector<int> adj[])
{
    vis[node] = 1;
    for (auto it: adj[node])
    {
        if (!vis[it])
        {
            findTopoSort(it, vis, s, adj);
        }
    }
    s.push(node);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    stack<int> s;

    for (int i = 0; i < V; ++i)
    {
        if (!vis[i])
        {
            findTopoSort(i, vis, s, adj);
        }
    }

    vector<int> ans;
    while (!s.empty())
    {
        ans.pb(s.top());s.pop();
    }

    return ans;
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

    
    vector<int> tvec = topoSort(V, adj);

    cout << "Topo Sort: ";
    for (auto it: tvec) cout << it << " ";
    cout << '\n';

    for (int i = 0; i < V; ++i) adj[i].clear();

    return 0;
}