#include "bits/stdc++.h"
using namespace std;

#define pb push_back

bool bipartiteDFS(int src, vector<int> adj[], int color[])
{
    for (auto it: adj[src])
    {
        if (color[it] == -1)
        {
            color[it] = 1 - color[src];
            if (!bipartiteDFS(it, adj, color))  return false;
        }
        else if (color[it] == color[src])   return false;
    }    

    return true;
}

bool checkBipartiteDFS(int n, vector<int> adj[])
{
    int color[n];
    memset(color, -1, sizeof(color));

    for (int i = 0; i < n; ++i){
        if (color[i] == -1)
        {
            color[i] = 1;
            if (!bipartiteDFS(i, adj, color))   return false;
        }
    } 

    return true;
}

bool bipartiteUsingBFS(vector<int> adj[], int color[], int node){
    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        int val = q.front();
        q.pop();

        for (auto it: adj[val])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[val];
                q.push(it);
            }
            else if (color[it] == color[val]){
                return false;
            }
        }
    }

    return true;
}

bool checkBipartite(int n, vector<int> adj[])
{
    int color[n];
    memset(color, -1, sizeof(color));

    for (int i = 0; i < n; ++i)
    {
        if (color[i] == -1)
        {
            if (!bipartiteUsingBFS(adj, color, i))   return false;
        }
    }

    return true;
}

void addEdge(int u, int v, vector<int> adj[])
{
    adj[u].pb(v), adj[v].pb(u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    vector<int> adj[8];

    addEdge(0, 1, adj);
    addEdge(1, 2, adj);
    addEdge(2, 3, adj);
    addEdge(3, 4, adj);
    addEdge(4, 6, adj);
    addEdge(6, 7, adj);
    addEdge(1, 7, adj);
    addEdge(4, 5, adj);

    (checkBipartiteDFS(8, adj)) ?   (cout << "YES" << endl) :   (cout << "NO" << endl)  ;

    if(checkBipartite(8, adj))
    {
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    
    for (int i = 0; i < 8; ++i) adj[i].clear();

    return 0;
}