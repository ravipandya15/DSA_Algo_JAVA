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
    priority_queue<int> pq; // it should be min Heap not max Heap
    // min heap
    priority_queue<int, vector<int>, greater<int>> mini;
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