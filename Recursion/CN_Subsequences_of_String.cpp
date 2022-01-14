#include<iostream>
#include<vector>
using namespace std;

int main()
{
    cout << "CN_Subsequences_of_String.cpp";
    return 0;
}

//giving wrong output
void solve(string str, int index, string output, vector<string> ans)
{
    // base case
    if (index >= str.length())
    {
        if (output.length() > 0)
        {
            ans.push_back(output);
        }
        return;
    }

    // exclude
    solve(str, index + 1, output, ans);

    // inclde
    output.push_back(str[index]);
    solve(str, index + 1, output, ans);
    output.pop_back();
}

vector<string> subsequences(string str){
    vector<string> ans;
    string output = "";
    solve(str, 0, output, ans);
    return ans;
}