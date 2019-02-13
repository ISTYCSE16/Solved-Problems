#include<bits/stdc++.h>
#define mx 1000000
#define ll long long

using namespace std;

ll tree[4*mx];
ll lazy[4*mx];

void update(ll si, ll ss, ll se, ll us, ll ue, ll diff)
{
    if (lazy[si] != 0)
    {
        tree[si] += (se-ss+1)*lazy[si];
        if (ss != se)
        {
            lazy[si*2]   += lazy[si];
            lazy[si*2 + 1]   += lazy[si];
        }
        lazy[si] = 0;
    }
    if (ss>se || ss>ue || se<us)
        return;
    if (ss>=us && se<=ue)
    {
        tree[si] += (se-ss+1)*diff;
        if (ss != se)
        {
            lazy[si*2]   += diff;
            lazy[si*2 + 1]   += diff;
        }
        return;
    }
    ll mid = (ss+se)/2;
    update(si*2, ss, mid, us, ue, diff);
    update(si*2+1, mid+1, se, us, ue, diff);
    tree[si] = tree[si*2] + tree[si*2+1];
}

ll query(ll ss, ll se, ll qs, ll qe, ll si)
{
    if (lazy[si] != 0)
    {
        tree[si] += (se-ss+1)*lazy[si];
        if (ss != se)
        {
            lazy[si*2] += lazy[si];
            lazy[si*2+1] += lazy[si];
        }
        lazy[si] = 0;
    }
    if (ss>se || ss>qe || se<qs)
        return 0;
    if (ss>=qs && se<=qe)
        return tree[si];
    ll mid = (ss + se)/2;
    return query(ss, mid, qs, qe, 2*si) + query(mid+1, se, qs, qe, 2*si+1);
}

int main()
{
    ll testCase, n, q, ask, x, y, v;

    scanf("%lld", &testCase);
    for(ll i = 1 ; i <= testCase ; ++i)
    {
        memset(tree, 0, 4*mx);
        memset(lazy, 0, 4*mx);
        scanf("%lld %lld", &n, &q);
        printf("Case %lld:\n",i);
        for(ll j = 0 ; j < q ; ++j)
        {
            scanf("%lld", &ask);
            if(ask == 0)
            {
                scanf("%lld %lld %lld", &x, &y, &v);
                update(1, 0, n - 1, x, y, v);
            }
            else
            {
                scanf("%lld %lld", &x, &y);
                ll ans = query(0, n - 1, x, y, 1);
                printf("%lld\n", ans);
            }

        }
    }
    return 0;
}
