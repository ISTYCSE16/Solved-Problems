#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define lli long long int
#define maxn 2020
#define inf 1e9+5

using namespace std;

struct Edge
{
    int from, to, wt;
    Edge(int _from, int _to, int _wt)
    {
        from = _from;
        to = _to;
        wt = _wt;
    }
};

vector <Edge> adj;
lli dist[maxn];

bool bellmanFord(int source, int n)
{
    for (int i = 0 ; i <= n ; ++i)
    {
        dist[i] = inf;
    }

    dist[source] = 0;
    for (int i = 1 ; i <= n - 1 ; ++i)
    {
        for (Edge e: adj)
        {
            if (dist[e.from] != inf && dist[e.to] > dist[e.from] + e.wt)
            {
                dist[e.to] = dist[e.from] + e.wt;
            }
        }
    }

    for (Edge e: adj)
    {
        if (dist[e.from] != inf && dist[e.to] > dist[e.from] + e.wt)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int c;
    int n, m;
    cin >> c;
    while(c--)
    {
        cin >> n >> m;
        for (int i = 0 ; i < m ; ++i)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj.push_back(Edge(u, v, w));
        }

        if (bellmanFord(0, n))
        {
            cout << "possible" << endl;
        }
        else
        {
            cout << "not possible" << endl;
        }
        adj.clear();
    }

    return 0;
}