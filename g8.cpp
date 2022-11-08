#include "bits/stdc++.h"
using namespace std;

#define pb push_back

void addEdge(int u, int v, vector<int> adj[])
{
    adj[u].pb(v), adj[v].pb(u);
}

//Topo Sort using Kahn's Algorithm
vector<int> topo(int V, vector<int> adj[])
{
    queue<int> q;
    vector<int> indegree(V, 0);

    for (int i = 0; i < V; ++i)
    {
        for (auto it: adj[i])   indegree[it]++;
    }

    for (int i = 0; i < V; ++i)
    {
        if (indegree[i] == 0)   q.push(i);
    }

    vector<int> topos;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        topos.pb(node);

        for (auto it: adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)  q.push(it);
        }
    }

    return topos;
}

int main()
{
    int V = 6;

    vector<int> adj[V];
    adj[5].pb(2);
    adj[5].pb(0);
    adj[4].pb(0);
    adj[4].pb(1);
    adj[3].pb(1);
    adj[2].pb(3);

    vector<int> ans = topo(V, adj);
    for (auto it: ans)  cout << it << ' ';
    cout << '\n';

    ans.clear();

    for (int i = 0; i < V; ++i) adj[i].clear();

    return 0;
}