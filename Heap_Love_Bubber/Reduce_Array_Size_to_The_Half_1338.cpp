#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

int minSetSize(vector<int>& arr) {
    unordered_map<int, int> map;
    priority_queue<int> maxi;
    int n = arr.size();
    int size = n;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        map[arr[i]]++;
    }

    for (auto x : map)
    {
        maxi.push(x.second);
    }

    while (size > n/2)
    {
        int temp = maxi.top();
        maxi.pop();
        size = size - temp;
        count++;
    }
    return count;
}