#include<vector>
#include<algorithm>
using namespace std;


int main()
{
    return 0;
}

// GFG solution
int smallestSubArrayWithSubGreatorthanX(vector<int> &arr, int k)
{
    int i = 0;
    int j = 0;
    int n = arr.size();
    int mini = n+1;
    int sum = 0;

    while (j < n)
    {
        while (sum <= k && j < n)
        {
            sum += arr[j];
            j++;
        }
        
        while (sum > k && i < n)
        {
            mini = min(mini, j - i);
            sum -= arr[i];
            i++;
        }
    }

    if (mini == n+1) return -1;
    return mini;
}

// my solution
int smallestSubArrayWithSubGreatorthanX_1(vector<int> &arr, int k)
{
    int i = 0;
    int j = 0;
    int mini = n+1;
    int sum = 0;

    while (j < n)
    {
        if (sum <= k)
        {
            sum += arr[j];
            j++;
        }
        else
        {
            mini = Math.min(mini, j - i);
            sum -= arr[i];
            i++;
        }
    }

    while (i < n)
    {
        if (sum > k)
        {
            mini = Math.min(mini, j - i);
            sum -= arr[i];
            i++;
        } else break;
    }

    if (mini == n+1) return 0;
    return mini;
}
