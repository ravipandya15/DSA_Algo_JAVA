#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    return 0;
}

// leetcode hard question
// GFG - IPL 2021 - Match Day 2
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    int i = 0;
    int j = 0;
    vector<int> ans;
    deque<int> de;

    while (j < n)
    {
        // calculation
        while (!de.empty() && de.back() < nums[j])
        {
            de.pop_back();
        }
        de.push_back(nums[j]);

        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            // find ans from calculation
            ans.push_back(de.front());

            // calculation to remove arr[i]
            if (!de.empty() &&  de.front() == nums[i])
            {
                de.pop_front();
            }

            // slide the window
            i++;
            j++;
        }
    }

    return ans;
}