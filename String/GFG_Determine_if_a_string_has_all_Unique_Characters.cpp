#include<iostream>
#include<vector>
using namespace std;

// best approach
// TC -> O(N)
// SC -> O(1)
bool uniqueCharacters(string str)
{
    int checker = 0;
    int n = str.size();

    for (int i = 0; i < n; i++)
    {
        int bit = str[i] - 'a';

        if ((checker & (1 << bit)) > 0)
        {
            return false;
        }
        checker = checker | (1 << bit);
    }

    return true;
}