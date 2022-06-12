#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    char findTheDifference1(string s, string t) {
        int sum1 = 0, sum2 = 0;
        for (char ch : s)
        {
            int pos = ch - 'a';
            sum1 += pos;
        }
        for (char ch : t)
        {
            int pos = ch - 'a';
            sum2 += pos;
        }
        int diff = sum2 - sum1;
        char ans = diff + 'a';
        return ans;
    }

    char findTheDifference2(string s, string t) {
        int sum1 = 0, sum2 = 0;
        for (char ch : s) sum1 += ch;
        for (char ch : t) sum2 += ch;
        char diff = sum2 - sum1;
        return diff;
    }

    char findTheDifference3(string s, string t) {
        char result = 0;
        for (char ch : s) result = result ^ ch;
        for (char ch : t) result = result ^ ch;
        return result;
    }
};