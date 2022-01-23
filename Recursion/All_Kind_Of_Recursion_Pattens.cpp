#include<iostream>
#include<vector>
using namespace std;

int main()
{
    cout << "Print_All_Recursion_Whose_Sum_is_K" << endl;
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    int sum = 2;

    vector<vector<int>> result1 = printAllRecursion(arr, sum);

    vector<vector<int>> result2 = printAnyOneRecursion(arr, sum);

    int result3 = countSubSeqencesWithSumK(arr, sum);

    return 0;
}

void solve1(int index, vector<int>& arr, int sum, int s, vector<vector<int>>& output,
                                vector<int>& result, int n)
{
    // base condition
    if (index == n)
    {
        if (sum == s)
            output.push_back(result);
        return;
    }


    // include
    s += arr[index];
    result.push_back(arr[index]);
    solve1(index + 1, arr, sum, s, output, result, n);
    result.pop_back();
    s -= arr[index];

    // exclude
    solve1(index + 1, arr, sum, s, output, result, n);
}

//Print_All_Recursion_Whose_Sum_is_K
//patern 1
vector<vector<int>> printAllRecursion(vector<int>& arr, int sum)
{
    vector<vector<int>> output;
    vector<int> result;
    solve1(0, arr, sum, 0, output, result, arr.size());
    return output;
}

bool solve2(int index, vector<int>& arr, int sum, int s, vector<vector<int>>& output,
                        vector<int>& result, int n)
{
    // base condition
    if (index == n)
    {
        if (sum == s)
        {
            output.push_back(result);
            return true;
        }
        return false;
    }


    // include
    s += arr[index];
    result.push_back(arr[index]);
    if (solve2(index + 1, arr, sum, s, output, result, n) == true)
        return true;

    result.pop_back();
    s -= arr[index];

    // exclude
    if (solve2(index + 1, arr, sum, s, output, result, n) == true)
        return true;

    return false;
}

//Print_Any_One_Recursion_Whose_Sum_is_K
// patern 2
vector<vector<int>> printAnyOneRecursion(vector<int>& arr, int sum)
{
    vector<vector<int>> output;
    vector<int> result;
    solve2(0, arr, sum, 0, output, result, arr.size());
    return output;
}

int solve3(int index, vector<int>& arr, int sum, int s, int n)
{
    // base condition
    if (index == n)
    {
        // condition satisfied
        if (sum == s)
        {
            return 1;
        }
        // condition not satisfied
        return 0;
    }


    // include
    s += arr[index];
    int left = solve3(index + 1, arr, sum, s, n);
    s -= arr[index];

    // exclude
    int right = solve3(index + 1, arr, sum, s, n);

    return left + right;
}

// Count the subsequences with sum k
// patern 3
int countSubSeqencesWithSumK(vector<int>& arr, int sum)
{
    return solve3(0, arr, sum, 0, arr.size());
}

