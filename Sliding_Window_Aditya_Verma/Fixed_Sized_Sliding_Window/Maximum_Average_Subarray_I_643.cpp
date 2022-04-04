#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    return 0;
}

double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    double sum = 0;
    double maxi = INT_MIN; 
    int i = 0, j = 0;
    while (j < n)
    {
        sum += nums[j];
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            maxi = max(maxi, sum);
            sum = sum - nums[i];
            i++;
            j++;
        }
    }

    return maxi/k;
}