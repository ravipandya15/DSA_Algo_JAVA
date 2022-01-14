#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int main()
{
    cout << "239. Sliding Window Maximum";
    //int[] arr = { 1, 3, -1, -3, 5, 3, 6, 7 };
    //int k = 3;
    vector<int> ans;
    ans.push_back(1);
    ans.push_back(3);
    ans.push_back(-1);
    ans.push_back(-3);
    ans.push_back(5);
    ans.push_back(3);
    ans.push_back(6);
    ans.push_back(7);
    int k = 1;

    vector<int> result = maxSlidingWindow(ans, k);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}

// TC -> O(N) + O(N) = O(N)
// SC -> O(K) -> at max deque will store k element
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans;
    deque<int> deque;

    for (int i = 0; i < n; i++)
    {
        while (!deque.empty() && deque.front() == i - k)
            deque.pop_front();

        while (!deque.empty() && nums[deque.back()] < nums[i])
            deque.pop_back();

        deque.push_back(i);

        if (i >= k - 1)
            ans.push_back(nums[deque.front()]);
    }
    return ans;
}