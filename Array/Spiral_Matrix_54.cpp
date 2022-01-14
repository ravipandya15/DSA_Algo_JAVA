#include<iostream>
#include<vector>
using namespace std;

int main()
{
    cout << "54 Spiral Matrix";
    return 0;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int row = matrix.size();
    int col = matrix[0].size();
    int count = 0;
    int total = row * col;

    // initialize Index;
    int startingRow = 0, starttingCol = 0, endingRow = row - 1, enddingCol = col - 1;

    while (count < total)
    {
        // print starting row
        for (int index = starttingCol; count < total && index <= enddingCol; index++)
        {
            ans.push_back(matrix[startingRow][index]);
            count++;
        }
        startingRow++;

        // print ending Col
        for (int index = startingRow; count < total && index <= endingRow; index++)
        {
            ans.push_back(matrix[index][enddingCol]);
            count++;
        }
        enddingCol--;

        // print ending Row
        for (int index = enddingCol; count < total && index >= starttingCol; index--)
        {
            ans.push_back(matrix[endingRow][index]);
            count++;
        }
        endingRow--;

        // print starting Col
        for (int index = endingRow; count < total && index >= startingRow; index--)
        {
            ans.push_back(matrix[index][starttingCol]);
            count++;
        }
        starttingCol++;
    }
    return ans;
}