#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
    return 0;
}

// TC -> O(NLogK)
int findKthLargest(vector<int>& nums, int k) {
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

    return mini.top();
}

// TC -> O(NLogK)
int findKthSmallest(vector<int>& nums, int k) {
    int n = nums.size();
    priority_queue<int> maxi;
    for (int i = 0; i < n; i++)
    {
        maxi.push(nums[i]);

        if (maxi.size() > k)
        {
            maxi.pop();
        }
    }

    return maxi.top();
}