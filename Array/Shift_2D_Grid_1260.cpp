#include<iostream>
#include<vector>
using namespace std;

int main()
{
    return 0;
}

// TC -> O(M*N)
// SC -> O(M * N)
vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> result(m, vector<int>(n, 0));
    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            int index = ( (r * n + c) + k ) % (m * n);
            int row = index / n;
            int col = index % n;

            //result.get(row).set(col, grid[r][c]);
            result[row][col] = grid[r][c];
        }
    }

    return result;  
}
