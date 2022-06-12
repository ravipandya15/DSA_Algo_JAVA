#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int largest = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++)
        {
            sum = (nums[i] == 1) ? sum + nums[i] : sum + -1;

            if (sum == 0)
            {
                largest = i+1;
            }
            else
            {
                if (map.find(sum) != map.end())
                {
                    largest = max(largest, i - map[sum]);
                }
                else
                {
                    map[sum] = i;
                }
            }
        }

        return largest;
    }
};