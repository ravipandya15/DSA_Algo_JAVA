#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
    return 0;
}

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    priority_queue<pair<int, int>> maxi;

    for (int i = 0; i < arr.size(); i++)
    {
        maxi.push({abs(arr[i] - x), arr[i]});

        if (maxi.size() > k)
        {
            maxi.pop();
        }
    }

    vector<int> ans;

    while (maxi.size() > 0)
    {
        ans.push_back(maxi.top().second);
        maxi.pop();
    }

    sort(ans.begin(), ans.end());

    return ans;
}