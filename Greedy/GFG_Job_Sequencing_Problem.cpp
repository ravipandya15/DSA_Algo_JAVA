#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    return 0;
}

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

bool comparator(Job j1, Job j2)
{
    return j1.profit > j2.profit;
}

vector<int> JobScheduling(Job arr[], int n) 
{ 
    int maxDeadline = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i].dead > maxDeadline)
        {
            maxDeadline = arr[i].dead;
        }
    }

    sort(arr, arr + 1, comparator);

    vector<int> slot(maxDeadline + 1, -1);
    vector<int> result(2);
    int jobCount = 0;
    int profit = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = arr[i].id;
                jobCount++;
                profit += arr[i].profit;
                break;
            }
        }
    }

    result.push_back(jobCount);
    result.push_back(profit);

    return result;
} 