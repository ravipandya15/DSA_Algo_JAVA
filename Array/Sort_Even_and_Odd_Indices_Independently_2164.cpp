#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    return 0;
}

vector<int> sortEvenOdd(vector<int>& nums) {
    vector<int> odd;
    vector<int> even;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            even.push_back(nums[i]);
        }
        else
        {
            odd.push_back(nums[i]);
        }
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end(), greater<int>());

    int i = 0;
    int evenI = 0;
    int oddI = 0;
    while (evenI < even.size()  || oddI < odd.size())
    {
        if (evenI < even.size())
        {
            nums[i] = even[evenI];
            i++;
            evenI++;
        }
        if (oddI < odd.size())
        {
            nums[i] = odd[oddI];
            i++;
            oddI++;
        }
    }

    return nums;
}