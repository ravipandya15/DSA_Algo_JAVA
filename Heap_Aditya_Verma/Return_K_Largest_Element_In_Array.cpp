#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
    return 0;
}

vector<int> KLargestElements(vector<int>& nums, int k) {
    vector<int> list;
    int n = nums.size();
    priority_queue<int, vector<int>, greater<int>> mini;
    for (int i = 0; i < n; i++)
    {
        mini.push(nums[i]);

        if (mini.size() > k)
        {
            mini.pop();
        }
    }

    while (!mini.empty())
    {
        list.push_back(mini.top());
        mini.pop();
    }
}