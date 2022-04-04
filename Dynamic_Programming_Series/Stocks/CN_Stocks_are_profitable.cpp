#include<vector>
#include<iostream>
using namespace std;

int main()
{
    return 0;
}

int maximumProfit(vector<int> &prices){
    int mini = prices[0];
    int profit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        int currentProfit = prices[i] - mini;
        profit = max(profit, currentProfit);
        mini = min(mini, prices[i]);
    }

    return profit;
}