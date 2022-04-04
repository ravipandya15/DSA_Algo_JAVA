#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> a1, pair<int, int> a2)
{
    return a2.first < a1.first;
}

int maxStocks(vector<int> &stocks, int k)
{
    int n = stocks.size();
    int maxi = 0;
    vector<pair<int, int>> stocksWithDay(n);

    for (int i = 0; i < n; i++)
    {
        stocksWithDay.push_back({stocks[i], i + 1});
    }

    sort(stocksWithDay.begin(), stocksWithDay.end(), compare);

    for (int i = 0; i < n; i++)
    {
        int count = k/stocksWithDay[i].first;
        maxi += min( count, stocksWithDay[i].second );
        k -= min( count, stocksWithDay[i].second ) * stocksWithDay[i].first;
    }

    return maxi;
}