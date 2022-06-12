#include<iostream>
#include<vector>
using namespace std;

class NumArray {
private:
    int n;
    vector<int> seg;
public:
    int build(vector<int> &nums, int left, int right, int node)
    {
        // base condition
        if (left == right)
        {
            return seg[node] = nums[left];
        }
        int middle = (left + right) / 2;
        int leftSum = build(nums, left, middle, 2 * node + 1);
        int rightSum = build(nums, middle + 1, right, 2 * node + 2);
        return seg[node] = leftSum + rightSum;
    }

    int update(int index, int val, int left, int right, int node)
    {
        // base condition
        if (index < left || index > right) return seg[node];
        if (left == right) return seg[node] = val;

        int middle = (left + right) / 2;
        int leftSum = update(index, val, left, middle, 2 * node + 1);
        int rightSum = update(index, val, middle + 1, right, 2 * node + 2);
        return seg[node] = leftSum + rightSum;
    }

    int sumRange(int left, int right, int ss, int se, int node)
    {
        // base condition
        if (se < left || ss > right) return 0;
        if (ss >= left && se <= right) return seg[node];

        int middle = (ss + se) / 2;
        int leftSum = sumRange(left, right, ss, middle, 2 * node + 1);
        int rightSum = sumRange(left, right, middle + 1, se, 2 * node + 2);
        return leftSum + rightSum;
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n);
        build(nums,0, n-1, 0);
    }
    
    void update(int index, int val) {
        update(index, val, 0, n-1, 0);
    }
    
    int sumRange(int left, int right) {
        return sumRange(left, right, 0, n-1, 0);
    }
};