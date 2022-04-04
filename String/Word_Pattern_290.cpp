#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;

int main()
{
    return 0;
}

bool wordPattern(string pattern, string s) {
    vector<string> arr;

    string temp = "";
    for (int i= 0 ;i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            arr.push_back(temp);
            temp = "";
        }
        else
        {
            temp += s[i];
        }
    }

    arr.push_back(temp);

    if (arr.size() != pattern.size()) return false;

    unordered_map<char, string> map;
    set<string> st;

    for (int i = 0; i < pattern.size(); i++)
    {
        if (map.find(pattern[i]) != map.end()) // means fount it in map
        {
            if (map[pattern[i]] != arr[i]) return false;
        }
        else
        {
            if (st.count(arr[i]) > 0)
            {
                return false;
            }
            map[pattern[i]] = arr[i];
            st.insert(arr[i]);
        }
    }

    return true;
}

