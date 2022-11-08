#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define vi vector<int>
#define vl vector<ll>

const ll mod = 1e9 + 7;
const ll maxNN = 1e6 + 1;

void dfs(int node, int parent, vector<int> &tin, vector<int> &low, int timer, vector<int> adj[], vector<int> &isArticulation)
{
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    int child = 0;

    for (auto it: adj[node])
    {
        if (it == parent)
        {
            continue;
        }

        if (!vis[it])
        {
            dfs(it, node, tin, low, timer, adj, isArticulation);

            low[node] = min(low[node], low[it]);

            child++;

            if (low[it] >= tin[node] && parent != -1)
            {
                isArticulation[node] = 1;
            }
        }
        else{
            low[node] = min(low[node], tin[it]);
        }
    }

    if (parent == -1 && child > 1)  isArticulation[node] = 1;
}

int main()
{
    int n, m; cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int u, v; cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }

    vector<int> tin(n, -1), low(n, -1), vis(n, 0), isArticulation(n, 0);
    int timer = 0;

    for (int i = 0; i < n; ++i)
    {
        if (!vis[i])    dfs(i, -1, vis, tin, low, timer, adj, isArticulation);
    }

    for (int i = 0; i < n; ++i)
    {
        if(isArticulation[i] == 1)  cout << i << '\n';
    }
    return 0;
}