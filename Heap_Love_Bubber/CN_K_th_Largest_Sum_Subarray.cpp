#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
    return 0;
}

int getKthLargest(vector<int> &arr, int k)
{
    int n = arr.size();
	priority_queue<int, vector<int>, greater<int>> mini;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            mini.push(sum);
            if (mini.size() > k)
            {
                mini.pop();
            }
        }
    }

    return mini.top();

}

int getKthLargest_2(vector<int> &arr, int k)
{
    int n = arr.size();
	priority_queue<int, vector<int>, greater<int>> mini;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (mini.size() < k)
            {
                mini.push(sum);
            }
            else
            {
                if (sum > mini.top())
                {
                    mini.pop();
                    mini.push(sum);
                }
                
            }
        }
    }

    return mini.top();

}