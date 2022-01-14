#include<iostream>
#include<stack>
#include<map>
#include<vector>
using namespace std;

int main()
{
    cout << "225. Implement Stack using Queues";
    return 0;
}

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    stack<int> stack;

    // as array is dictinct as per question
    map<int, int> dict;
    for (int i = nums2.size() - 1; i >= 0; i--)
    {
        while (!stack.empty() && stack.top() <= nums2[i])
            stack.pop();

        if (stack.empty())
            dict.insert({nums2[i], -1});
        else
            dict.insert({nums2[i], stack.top()});

        stack.push(nums2[i]);
    }

    for (int i = 0; i < nums1.size(); i++)
    {
        ans[i] = dict[nums1[i]];
    }
    return ans;
}