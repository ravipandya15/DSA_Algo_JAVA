#include<vector>
#include<algorithm>
using namespace std;


int main()
{
    return 0;
}

vector<int> sortArrayByParity(vector<int>& nums) {
    int j = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2 == 0)
        {
            swap(nums[i], nums[j]);
            j++;
        }
    }

    return nums;
}