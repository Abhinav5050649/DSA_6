#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define ll long long
#define vi vector<int>
#define vl vector<ll>

const ll mod = 1e9 + 7;
const ll maxNN = 1e6 + 1;

//Bridges in Graph
void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int timer, vector<int> adj[])
{
    vis[node] = 1;
    tin[node] = low[node] = timer++;

    for (auto it: adj[node])
    {
        if (!vis[it])
        {
            dfs(it, node, vis, tin, low, timer, adj);

            low[node] = min(low[node], low[it]);

            if (low[node] > tin[it])
            {
                cout << node << ' ' << it << '\n';
            }
            else{
                low[node] = min(tin[node], low[it]);
            }
        }
    }
}

int main()
{
    int n, m; cin >> n >> m;
    vector<int> adj[n];

    for (int i = 0; i < n; ++i)
    {
        int u, v; cin >> u >> v;

        adj[u].pb(v), adj[v].pb(u);    
    }

    vector<int> vis(n, 0), tin(n, -1), low(n, -1);
    int timer = 0;

    for (int i = 0; i < n; ++i)
    {
        if (!vis[i])
        {
            dfs(i, -1, vis, tin, low, timer, adj);
        }
    }

    return 0;
}
