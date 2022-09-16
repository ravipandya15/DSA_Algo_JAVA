#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


/// Very Very Most Important point

// this approach will only work if all iteams are +ve.

// if we have -ve numbers too , then we need to use HashMap -> maximum subarray sum = 0
// need to use HashMap

int largestSubArrayOfSumK(vector<int> &arr, int k)
{
    int n = arr.size();
    int i = 0; 
    int j = 0;
    int sum = 0;
    int maxi = INT_MIN;

    while (j < n)
    {
        // calculation
        sum = sum + arr[j];

        if (sum < k)
        {
            j++;
        }
        else if (sum == k)
        {
            maxi = max(maxi, j-i+1);
            j++;
        }
        else if (sum > k)
        {
            while (sum > k)
            {
                sum = sum - arr[i];
                i++;
            }
            j++;
        }
    }

    return maxi;
}

int main()
{
    return 0;
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(1);

    int ans = largestSubArrayOfSumK(arr, 5);

    cout << "ans is " << ans << endl;
}

