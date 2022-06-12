#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// TC -> O(N^2)
// SC -> O(N)
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> map;
        for (int k : nums3)
        {
            for (int l : nums4)
            {
                map[k + l]++;
            }
        }

        int count = 0;
        for (int i : nums1)
        {
            for (int j : nums2)
            {
                if (map.find(-(i + j)) != map.end())
                {
                    count += map[-(i+j)];
                }
                // direct count += map[-(i+j)] will also work
            }
        }

        return count;
    }
};