#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#define ll long long
#define mx 1000100

using namespace std;

char store[mx];
ll visited[mx*4];

void query(ll l, ll r, ll L, ll R, ll at)
{
    if(l > R || r < L) return;
    if(l <= L && r >= R)
    {
        visited[at]++;
        return;
    }
    ll mid = (L + R) / 2;
    query(l, r, L, mid, at*2);
    query(l, r, mid + 1, R, at*2 + 1);
}

void toggle(ll at, ll L, ll R, ll pos)
{
    if(visited[at] != 0 && L != R)
    {
        visited[at*2] += visited[at];
        visited[at*2+1] += visited[at];
        visited[at] = 0;
    }
    if(pos < L || pos > R)
    {
        return;
    }
    if(L == R)
    {
        if(visited[at] % 2 == 1)
        {
            if(store[L] == '1')
            {
                store[L] = '0';
            }
            else
            {
                store[L] = '1';
            }
        }
        visited[at] = 0;
        return;
    }
    ll mid = (L + R) / 2;
    toggle(at*2, L, mid, pos);
    toggle(at*2 + 1, mid + 1, R, pos);
}

int main()
{
    ll testCase, q, i_s, i_e, pos;
    char ask;
    scanf("%lld", &testCase);
    for(ll i = 1; i <= testCase ; ++i)
    {
        memset(visited, 0, 4*mx);
        memset(store, 0, mx);
        scanf("%s", store);
        ll size = strlen(store);
        scanf("%lld", &q);
        printf("Case %lld:\n", i);
        for(ll j = 1 ; j <= q ; ++j)
        {
            scanf(" %c", &ask);
            if(ask == 'I')
            {
                scanf("%lld %lld", &i_s, &i_e);
                query(i_s - 1, i_e - 1, 0, size - 1, 1);
            }
            else
            {
                scanf("%lld", &pos);
                toggle(1, 0, size - 1, pos - 1);
                printf("%c\n", store[pos - 1]);
            }
        }
    }
    return 0;
}
