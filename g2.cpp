#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define pb push_back
const ll mod = 1e9 + 7;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef vector<int> vi;
typedef vector<vi> vii;

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

void DFS_Undirected(ll node, vl &vis, vl &dfs, vl adj[])
{
    vis[node] = 1;
    dfs.pb(node);

    for (auto it: adj[node])
    {
        if (!vis[it])   DFS_Undirected(it, vis, dfs, adj);
    }
}

void addEdge(vl adj[], ll u, ll v)
{
    adj[u].pb(v);
    adj[v].pb(u);
}

vl adj[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    ll n, m; cin >> n >> m;
    for (ll i = 0; i < m; ++i)
    {
        ll u, v; cin >> u >> v;
        addEdge(adj, u, v);
    }

    vl vis(n + 1, 0), dfs;

    for (ll i = 1; i <= n; ++i)
    {
        if (!vis[i])    DFS_Undirected(i, vis, dfs, adj);
    }

    for (auto it: dfs)  cout << it << " ";
    cout << endl;

    vis.clear(), dfs.clear();
    for (ll i = 0; i <= n; ++i)  adj[i].clear();
    return 0;
}