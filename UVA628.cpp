#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <pair<int,int>> ans;

int knapsack(int n, int W, int profits[], int weights[])
{
    int ans[n][W];
    for (int i = 0 ; i <= n ; ++i)
    {
        for (int w = 0 ; w <= W ; ++w)
        {
            if (i == 0 || w == 0) ans[i][w] = 0;
            else if (w >= weights[i - 1]) 
        }
    }
}