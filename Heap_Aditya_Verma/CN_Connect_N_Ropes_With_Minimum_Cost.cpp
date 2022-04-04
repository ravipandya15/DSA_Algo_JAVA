#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
    return 0;
}

long long connectRopes(int* arr, int n)
{
    // it's better to create Priority Queue of Long Long -> GFG par int thi test cases pass nathi thata
    priority_queue<int, vector<int>, greater<int>> mini;
    for (int i = 0; i < n; i++)
    {
        mini.push(arr[i]);
    }

    long long cost = 0;
    while (mini.size() > 1)
    {
        int first = mini.top();
        mini.pop();
        int second = mini.top();
        mini.pop();

        cost += first + second;
        mini.push(first + second);
    }

    return cost;
}