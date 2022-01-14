#include<iostream>
#include<vector>
using namespace std;

int main()
{
    cout << "Letter_Combinations_of_a_Phone_Number_17.cpp";
    return 0;
}

void Solve(string digits, int index, string output, 
                                  string mapping[], vector<string>& result)
{
    if (index == digits.length())
    {
        result.push_back(output);
        return;
    }

    int number = digits[index] - '0';
    string value = mapping[number];

    for (int i = 0; i < value.length(); i++)
    {
        output.push_back(value[i]);
        Solve(digits, index + 1, output, mapping, result);
        output.pop_back(); // knows as back-tracking
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> result;

    if (digits.length() == 0) return result;
    string output;
    string mapping[] = { "", "", "abc","def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    Solve(digits, 0, output, mapping, result);
    return result;  
}