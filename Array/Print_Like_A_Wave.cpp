#include<iostream>
#include<vector>


int main()
{
    cout << "CN) Print like a wave";
    return 0;
}

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> result;

    for (int col = 0; col < mCols; col++)
    {
        if ((int)(col & 1) == 1)
        {
            // Odd index -> Bottom to Top
            for (int row = nRows - 1; row >= 0; row--)
            {
                result.push_back(arr[row][col]);
            }
        }

        else
        {
            // Even or 0 index -> Top to Bottom
            for (int row = 0; row < nRows; row++)
            {
                result.push_back(arr[row][col]);
            }
        }
    }

    return result;
}