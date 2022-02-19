#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main()
{
    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;

    int ans = sumOfKSubArray(arr, 7, k);
    cout << ans << endl;
    return 0;
}

int sumOfKSubArray(int arr[], int n, int k)
{
    deque<int> maxi; // -> store value in decreasing order
    deque<int> mini; // -> store value in increasing order

    // process 1st window of size k
    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while (!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();
        
        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans = arr[maxi.front()] + arr[mini.front()];

    // process for remaining elements
    for (int i = k; i < n; i++)
    {
        // remove out of index elements (indexs)
        while (!maxi.empty() && i - maxi.front() >= k)
            maxi.pop_front();
        
        while (!mini.empty() && i - mini.front() >= k)
            mini.pop_front();

        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while (!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();
        
        maxi.push_back(i);
        mini.push_back(i);

        ans += arr[maxi.front()] + arr[mini.front()];
    }

    return ans;
}