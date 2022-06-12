#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) {

    // with Set
    unordered_set<int> set;
    for (int i = 0; i < n; i++)
    {
        if (set.find(a1[i]) == set.end())
        {
            set.insert(a1[i]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (set.find(a2[i]) == set.end())
        {
            return "No";
        }
    }

    return "Yes";

    // With Map
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        map[a1[i]]++;
    }

    for (int i = 0; i < m; i++)
    {
        if (map.find(a2[i]) == map.end())
        {
            return "No";
        }
    }

    return "Yes";
}