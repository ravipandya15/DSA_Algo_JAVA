#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
    return 0;
}

int signum(int a, int b)
{
    if (a == b) return 0;
    else if (a > b) return 1;
    else return -1;
}

void findMedian(int element, priority_queue<int> &maxi, priority_queue<int, vector<int>, greater<int>> &mini, int &median)
{
    switch(signum(maxi.size(), mini.size()))
    {
        case 0: // maxi.size() = n and mini.size() = n
            if (element > median)
            {
                mini.push(element);
                median = mini.top();
            }
            else
            {
                maxi.push(element);
                median = maxi.top();
            }
            break;
        
        case 1: // maxi.size() = n and mini.size() = n - 1
            if (element > median)
            {
                mini.push(element);
                median = ( maxi.top() + mini.top() ) / 2;
            }
            else
            {
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(element);
                median = ( maxi.top() + mini.top() ) / 2;
            }
            break;

        case -1: // maxi.size() = n - 1 and mini.size() = n
            if (element > median)
            {
                maxi.push(mini.top());
                mini.pop();
                mini.push(element);
                median = ( maxi.top() + mini.top() ) / 2;
            }
            else
            {
                maxi.push(element);
                median = ( maxi.top() + mini.top() ) / 2;
            }
            break;
    }

    return;
}

vector<int> findMedian(vector<int> &arr, int n){

    vector<int> ans;
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;
    int median = -1;

    for (int i = 0; i < n; i++)
    {
        findMedian(arr[i], maxi, mini, median);
        ans.push_back(median);
    }

    return ans;
}
