#include "bits/stdc++.h"
using namespace std;

#define pb push_back

//Bipartite Graph Colouring
//1) Using BFS
//2) Using DFS

bool bipartiteGraphUsingDFS(int node, vector<int> adj[], int color[])
{
    for (auto it: adj[node])
    {
        if (color[it] == -1)
        {
            color[it] = 1 - color[node];
            if (!bipartiteGraphUsingDFS(it, adj, color))    return false;
            else if (color[it] == color[node])  return false;
        }
    }
    return true;
}

bool isBipartiteDFS(int n, vector<int> adj[])
{
    int color[n];
    memset(color, -1, sizeof(color));

    for (int i = 0; i < n; ++i)
    {
        if (color[i] == -1)
        {
            color[i] = 1;
            if (!bipartiteGraphUsingDFS(i, adj, color)) return false;
        }
    }

    return true;
}

bool bipartiteGraphUsingBFS(int src, vector<int> adj[], int color[])
{
    queue<int> q;
    q.push(src);
    color[src] = 1;

    while (!q.empty()){
        int node = q.front();
        q.pop();

        for (auto it: adj[node]){

            if (color[it] == -1){
                color[it] = 1 - color[node];
                q.push(it);
            }else if (color[it] == color[node])
            {
                return false;
            }
        }
    }

    return true;
}

bool checkBipartite(vector<int> adj[], int n)
{
    int color[n];
    memset(color, -1, sizeof(color));

    for (int i = 0; i < n; ++i)
    {
        if (color[i] == -1)
        {
            if (!bipartiteGraphUsingBFS(i, adj, color)) return false;
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

    (isBipartiteDFS(8, adj)) ?   (cout << "YES" << endl) :   (cout << "NO" << endl)  ;
    if(checkBipartite(adj, 8))
    {
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    
    for (int i = 0; i < 8; ++i) adj[i].clear();

    return 0;
}