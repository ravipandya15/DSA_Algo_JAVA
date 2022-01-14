#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    cout << "CN_Merge_Sort";
    return 0;
}

void Solve(int index, string str, vector<string>& result)
{
    // base case
    if (index == str.length())
    {
        result.push_back(str);
        return;
    }
        

    for (int i = index; i < str.length(); i++)
    {
        swap(str[i], str[index]);
        Solve(index + 1, str, result);
        swap(str[i], str[index]);
    }
}

vector<string> generatePermutations(string &str)
{
    vector<string> result;
    Solve(0, str, result);
    sort(result.begin(), result.end());

    // if we want to sort vector in descei=nding order
    //sort(result.begin(), result.end(), greater<int>());
    return result;
}