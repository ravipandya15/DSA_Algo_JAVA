#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
    return 0;
}

long long minCost(long long arr[], long long n) {
        // Your code here
        // same as connect N ropes with minimum cost
        priority_queue<long long, vector<long long>, greater<long long>> mini;
        for (int i = 0; i < n; i++)
        {
            mini.push(arr[i]);
        }
    
        long long cost = 0;
        while (mini.size() > 1)
        {
            long long first = mini.top();
            mini.pop();
            long long second = mini.top();
            mini.pop();
    
            cost += first + second;
            mini.push(first + second);
        }
    
        return cost;
}

