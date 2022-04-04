#include<iostream>
#include<vector>
using namespace std;

int isPossible (string S)
{
    vector<int> arr(26, 0);
    for (int i = 0; i < S.length(); i++)
    {
        arr[S[i] - 'a']++;
    }
    
    int count = 0;
    
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] % 2 != 0)
        {
            count++;
        }
        if (count > 1)
        {
            return 0;
        }
    }
    
    return 1;
}