#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    return 0;
}

// commented line is also valid -> instead on common line to add sub[j]
int maximumSumSubarray(int K, vector<int> &Arr , int N){
    int maxi = INT_MIN;
    int sum = 0;
    int i = 0, j = 0;
    while (j < N)
    {
        sum = sum + Arr[j];
        if (j-i+1 < K)
        {
            // sum += Arr[j];
            j++;
        }
        else if (j - i + 1 == K)
        {
            // sum = sum + Arr[j];
            maxi = max(maxi, sum);
            sum = sum - Arr[i];
            i++;
            j++;
        }
    }

    return maxi;
}