#include<vector>
#include<algorithm>
using namespace std;


int main()
{
    return 0;
}
// [1,3,2,2,2]
// for this test case while condition on line no : 29 and 30 is written instead of if condition.

int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size();
    int low = 0, high = n - 1;

    while (low + 1 < n && nums[low] <= nums[low + 1]) low++;
    while (high - 1 >= 0 && nums[high - 1] <= nums[high]) high--;

    if (low == n - 1) return 0;

    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = low; i <= high; i++)
    {
        mini = min(mini, nums[i]);
        maxi = max(maxi, nums[i]);
    }

    while (low - 1 >= 0 && nums[low - 1] > mini) low--;
    while (high + 1 < n && nums[high + 1] < maxi) high++;

    return high - low + 1;
}