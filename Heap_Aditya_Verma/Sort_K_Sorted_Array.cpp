#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
    return 0;
}

// TC -> O(NLogK)
// also known as Sort nearly sorted array
// ased in Flipkart
// used Max Heap
vector<int> sortKSortedArray(vector<int> nums, int k)
{
    int n = nums.size();
    int index = 0;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(nums[i]);
        if (pq.size() > k)
        {
            nums[index++] = pq.top();
            pq.pop();
        }
    }

    return nums;
}