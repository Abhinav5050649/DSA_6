#include "bits/stdc++.h"
using namespace std;

#define pb push_back

//Dijkstra's Algorithm 

int main()
{
    int n = 5, m = 6, src = 1;

    vector<pair<int, int>> g[n + 1];
    g[1].pb({2, 2});
    g[1].pb({4, 1});
    g[2].pb({1, 2});
    g[2].pb({5, 5});
    g[2].pb({3, 4});
    g[3].pb({2, 4});
    g[3].pb({4, 3});
    g[3].pb({5, 1});
    g[4].pb({1, 1});
    g[4].pb({3, 3});
    g[5].pb({2, 5});
    g[5].pb({3, 1});

    vector<int> distTo(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distTo[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        vector<pair<int, int>>::iterator it;

        for (it = g[prev].begin(); it != g[prev].end(); ++it){
            int next = it->first;
            int nextDist = it->second;

            if (distTo[next] > distTo[prev] + nextDist)
            {
                distTo[next] = distTo[prev] + nextDist;
                pq.push(make_pair(distTo[next], next));
            }
        }
    }

    cout << "The distances from source are: \n";
    for (int i = 1; i <= n; ++i)
    {
        cout << distTo[i] << ' ';
    }
    cout << '\n';

    distTo.clear();
    for (int i = 0; i <= n; ++i)    g[i].clear();

    return 0;
}