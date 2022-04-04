#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> candyStore(int candies[], int N, int k)
{
    sort(candies, candies + N);
    int i = 0;
    int j = N-1;
    int mini = 0, maxi = 0;
    
    while (i <= j)
    {
        mini += candies[i];
        i++;
        j = j - k;
    }
    
    i = 0;
    j = N-1;
    
    while (i <= j)
    {
        maxi += candies[j];
        j--;
        i = i + k;
    }
    
    vector<int> ans;
    ans.push_back(mini);
    ans.push_back(maxi);
    
    return ans;
}