#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int minSwaps(vector<int>&nums)
{
    int n = nums.size();
    unordered_map<int, int> map;
    vector<int> temp = nums;
    sort(temp.begin(), temp.end());
    int ans = 0;

    // create map
    for (int i = 0; i < n; i++)
    {
        map[nums[i]] = i;
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != temp[i])
        {
            ans++;
            int init = nums[i];
            swap(nums[i], nums[map[temp[i]]]);
            // update map index
            map[init] = map[temp[i]];
            map[temp[i]] = i;
        }
    }

    return ans;

}