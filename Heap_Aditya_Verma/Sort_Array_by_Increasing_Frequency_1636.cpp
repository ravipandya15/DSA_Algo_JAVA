#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

int main()
{
    return 0;
}

vector<int> frequencySort(vector<int>& nums) {


    // not working
    // check Java code

    int size = nums.size();
    unordered_map<int, int> map;

    for (int i = 0; i < size; i++)
    {
        map[nums[i]]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (auto i = map.begin(); i != map.end(); i++)
    {
        int freq = i->second;
        int value = i->first;
        pq.push({freq, value});
    }

    vector<int> ans;
    int index = 0;
    while (pq.size() > 0)
    {
        int freq = pq.top().first;
        int value = pq.top().second;
        for (int i = 0; i < freq; i++)
        {
            ans.push_back(value);
        }
        pq.pop();
    }

    return ans;
}