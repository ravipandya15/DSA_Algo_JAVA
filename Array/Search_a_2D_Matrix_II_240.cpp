#include<iostream>
#include<vector>
using namespace std;

int main()
{
    cout << "Search_a_2D_Matrix_II_240.cpp";
    return 0;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();

    int rowIndex = 0;
    int colIndex = col - 1;

    while (rowIndex < row && colIndex >= 0)
    {
        if (matrix[rowIndex][colIndex] == target)
            return true;

        if (matrix[rowIndex][colIndex] < target)
            rowIndex++;

        else
            colIndex--;
    }
    return false;
}