#include "bits/stdc++.h"
using namespace std;

#define pb push_back

void addEdge(int u, int v, vector<int> adj[])
{
    adj[u].pb(v), adj[v].pb(u);
}

//Cycle Detection using BFS
bool isCyclic(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; ++i)
    {
        for (auto it: adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; ++i)
    {
        if (indegree[i] == 0)   q.push(i);
    }

    int cnt = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ++cnt;

        for (auto it: adj[node])
        {
            indegree[it]--;
            if (indegree[it]    ==  0)  q.push(it);
        } 
    }

    if (cnt == V)   return false;
    else    return true;
}

int main()
{
    int V= 6;
    vector<int> adj[V];
    adj[5].pb(2);
    adj[5].pb(0);
    adj[4].pb(0);
    adj[4].pb(1);
    adj[3].pb(1);
    adj[2].pb(3);

    cout << isCyclic(V, adj) << '\n';

    for (int i = 0; i < V; ++i) adj[i].clear();

    return 0;
}