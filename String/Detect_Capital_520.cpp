#include<vector>
#include<iostream>
using namespace std;

bool detectCapitalUse(string word) {
    int n = word.size();
    if (isupper(word[0]))
    {
        if (word.size() > 1 && isupper(word[1]))
        {
            for (int i = 2; i < n; i++)
            {
                if (islower(word[i])) return false;
            }
        }
        else
        {
            for (int i = 1; i < n; i++)
            {
                if (isupper(word[i])) return false;
            }
        }
    }
    else
    {
        for (int i = i; i < n; i++)
        {
            if (isupper(word[i])) return false;
        }
    }

    return true;
}