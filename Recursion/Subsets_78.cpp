#include<iostream>
#include<vector>
using namespace std;

int main()
{
    cout << "Subsets_78.cpp";
    return 0;
}

//code help approach
//using Recursion
void solve(vector<int>& nums, int index, vector<int> output, vector<vector<int>>& result)
{
    if (index >= nums.size())
    {
        result.push_back(output);
        return;
    }

    // exclude
    solve(nums, index + 1, output, result);

    //include
    output.push_back(nums[index]);
    solve(nums, index + 1, output, result);
    output.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> output;
    solve(nums, 0, output, result);
    return result;
}

// Striver approach
void findSubSet(int index, vector<int>& nums, vector<int> curList, vector<vector<int>>& resultList)
{
    resultList.push_back(curList);
    for (int i = index; i < nums.size(); i++)
    {
        curList.push_back(nums[i]);
        findSubSet(i + 1, nums, curList, resultList);
        curList.pop_back();
    }
}

vector<vector<int>> subsets1(vector<int>& nums) {
    vector<vector<int>> resultList;
    vector<int> curList;
    findSubSet(0, nums, curList, resultList);
    return resultList;
}


