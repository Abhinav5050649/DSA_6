#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
#define pb push_back

bool checkCycleUsingBFS(ll s, ll V, vll &vis, vll adj[])
{
    queue<pair<ll, ll>> q;
    vis[s] = 1;
    q.push({s, -1});

    while (!q.empty())
    {
        ll node = q.front().first, par = q.front().second;

        for (auto it: adj[node])
        {
            if (!vis[it])
            {
                q.push({it, node});
                vis[it] = 1;
            }
            else if (it != par){
                return true;
            }
        }   
    }

    return false;
}

bool isCycleBFS(ll V, vll adj[])
{
    vll vis(V + 1, 0);
    for (ll i = 1; i <= V; ++i)
    {
        if (!vis[i])
        {
            if (checkCycleUsingBFS(i, V, vis, adj)) return true;
        }
    }
    vis.clear();
    return false;
}

bool checkCycleUsingDFS(ll node, ll parent, ll V, vll &vis, vll adj[])
{
    vis[node] = 1;
    
    for (auto it: adj[node])
    {
        if (!vis[it])
        {
            if (checkCycleUsingDFS(it, node, V, vis, adj))  return true;
        }
        else if (it != parent)
        {
            return true;
        }
    }
    return false;
}

bool isCycleDFS(ll V, vll adj[])
{
    vll vis(V + 1, 0);

    for (ll i = 0; i <= V; ++i)
    {
        if (!vis[i])
        {
            if (checkCycleUsingDFS(i, -1, V, vis, adj)) return true;
        }
    }
    vis.clear();
    return false;
}

void addEdge(ll u, ll v, vll adj[])
{
    adj[u].pb(v);
    adj[v].pb(u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);


    vll adj[6];
    addEdge(0, 1, adj);
    addEdge(0, 2, adj);
    addEdge(1, 5, adj);
    addEdge(2, 3, adj);
    addEdge(3, 4, adj);

    cout << isCycleBFS(5, adj) << endl;
    cout << isCycleDFS(5, adj) << endl; 
    for (ll i = 0; i <= 5; ++i) adj[i].clear();

    return 0;
}