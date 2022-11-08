#include "iostream"
#include "algorithm"
using namespace std;

const int MAXV = 1e4 + 5;
int id[MAXV], nodes, edges;

pair<long long, pair<int, int>> p[MAXV];

void init()
{
    for (int i = 0; i < MAXV; ++i)  id[i] = i;
}

int root(int x)
{
    while (id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p = root(x), q = root(y);
    id[p] = id[q];
}

long long kruskal(pair<long long, pair<int, int>> p[])
{
    int x = 0, y = 0; 
    long long cost = 0, minCost= 0;

    for (int i = 0; i < edges; ++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;

        cost = p[i].first;

        if (root(x) != root(y))
        {
            minCost += cost;
            union1(x, y);
        }

    }
    
    return minCost;
}

int main()
{
    int x, y;
    long long wt, cost, minCost;
    
    init();

    cin >> nodes >> edges;

    for (int i = 0; i < edges; ++i)
    {
        cin >> x >> y >> wt;
        p[i] = make_pair(wt, make_pair(x, y));
    }

    sort(p, p + edges);
    minCost = kruskal(p);

    cout << minCost << '\n';

    return 0;
}