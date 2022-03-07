#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;

int main()
{
    return 0;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        map[nums[i]]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for(auto i = map.begin(); i != map.end(); i++)
    {
        pq.push({i->second, i-> first});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    vector<int> ans;

    while (pq.size() > 0)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}