#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define pb push_back
const ll mod = 1e9 + 7;
typedef vector<ll> vll;
typedef vector<int> vii;

void swap(ll &a, ll &b)
{
    a ^= b; b ^= a; a ^= b;
}

ll bin_exp(ll a, ll b)
{
    a %= mod;
    ll res = 1;

    while (b > 0)
    {
        if (b & 1)  res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    else return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return ((a * b)/gcd(a, b));
}

vll BFS_Undirected(ll V, vll adj[])
{
    queue<ll> q;
    vll bfs, vis(V + 1, 0);

    q.push(0), vis[0] = 1;

    while (!q.empty())
    {
        ll node = q.front(); q.pop();
        vis[node] = 1;
        bfs.pb(node);

        for (auto it: adj[node])
        {
            if (!vis[it])
            {
                q.push(it); vis[it]= 1;
            }
        }
    }

    return bfs;
}

// void DFS_Undirected(ll node, vl &vis, vl &dfs, vl adj[])
// {
//     vis[node] = 1;
//     dfs.pb(node);

//     for (auto it: adj[node])
//     {
//         if (!vis[it])   DFS_Undirected(it, vis, dfs, adj);
//     }
// }

/*
vll BFS(ll V, vll adj[])
{
    queue<ll> q;
    vll bfs, vis(V, 0);

    q.push(0);
    vis[0] = 1;

    while (!q.empty())
    {
        ll node = q.front();
        q.pop();
        bfs.pb(node);

        for (auto it: adj[node])
        {
            if (!vis[it]){
                q.push(it);
                vis[it] = 1;
            }
        }
    }

    return bfs;
}
*/

void solve()
{
    ll n, m; cin >> n >> m;
    vll adj[n + 1];
    for (ll i = 0; i < m; ++i){
        ll u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vll bfs =  BFS_Undirected(n, adj);
    for (auto it: bfs)  cout << it << " ";
    cout << endl;
    bfs.clear();
    for (ll i = 0; i < n; ++i)  adj[i].clear();

    // vll vis(n + 1, 0), dfs;
    // for (ll i = 1; i <= n; ++i)
    // {
    //     if (!vis[i])    DFS_Undirected(i, vis, dfs, adj);
    // }

    // for (auto it: dfs)  cout << it << " ";
    // cout << endl;
    // vis.clear(), dfs.clear();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    solve();

    return 0;
}