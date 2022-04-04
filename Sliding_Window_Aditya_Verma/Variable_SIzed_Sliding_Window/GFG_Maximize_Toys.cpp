#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int toyCount(int N, int K, vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int i = 0, j = 0;
    int maxi = 0;
    int sum = 0;
    
    while (j < N)
    {
        // calculation
        sum += arr[j];
        
        if (sum <= K)
        {
            maxi = max(maxi, j - i + 1);
            j++;
        }
        else if (sum > K)
        {
            while (sum > K)
            {
                sum -= arr[i];
                i++;
            }
            j++;
        }
    }
    
    return maxi;
}