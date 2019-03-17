#include <bits/stdc++.h>
#define mx 30010
#define ll long long
#define INF 99999999999999999

using namespace std;

struct Node
{
		ll at, cost;
		Node(ll _at, ll _cost)
		{
				at = _at;
				cost = _cost;
		}
};

bool operator<(Node A, Node B)
{
    return B.cost > A.cost;
}

struct Edge
{
    ll v, w;
};


vector < Edge > adj[mx];
priority_queue < Node > PQ;
ll dist[mx];

void bfs(ll source)
{
    ll max = -1*INF;
    for(ll i = 0 ; i <= mx ; ++i)
    {
        dist[i] = INF;
    }
    dist[source] = 0;
    PQ.push(Node(source, 0));
    while(!PQ.empty())
    {
        Node node = PQ.top();
        PQ.pop();
        if(node.cost != dist[node.at])
        {
            continue;
        }
        for(Edge e : adj[node.at])
        {
            if(dist[e.v] > node.cost + e.w)
            {
                dist[e.v] = node.cost + e.w;
                PQ.push(Node(e.v, dist[e.v]));
            }
        }
    }
}

int main()
{
    ll testCase;
    ll vertex;
    Edge edge;
    ll max;
    ll disto;
    ll u, v, w;
		ll max_ind;
    scanf("%lld", &testCase);
    for(ll i = 1; i <= testCase ; ++i)
    {
        max = -1*INF;
        scanf("%lld", &vertex);
        for(ll j = 0 ; j <= mx ; ++j)
        {
            adj[j].clear();
        }
        for(ll j = 1; j < vertex ; ++j)
        {
            scanf("%lld %lld %lld", &u, &v, &w);
            edge.v = v;
            edge.w = w;
            adj[u].push_back(edge);
            edge.v = u;
            edge.w = w;
            adj[v].push_back(edge);
        }
				bfs(0);
				for(ll j = 0 ; j < vertex ; ++j)
				{
						if(max < dist[j])
						{
								max_ind = j;
								max = dist[j];
						}
				}
				bfs(max_ind);
				for(ll j = 0 ; j < vertex ; ++j)
				{
						if(max < dist[j])
						{
								max = dist[j];
						}
				}
        printf("Case %lld: %lld\n",i, max);
    }
    return 0;
}
