#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
    cout << "449. Rotating Oranges";
    return 0;
}

int orangesRotting(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;
    int m = grid.size();
    int n = grid[0].size();
    int time = 0, totalOranges = 0, rottenOranges = 0;
    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] != 0) totalOranges++;
            if (grid[i][j] == 2) q.push({i, j});
        }
    }

    int dx[4] = {0, 0, 1,-1};
    int dy[4] = {1, -1, 0,0};

    while (!q.empty())
    {
        int k = q.size();
        rottenOranges +=k;
        while(k--)
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] != 1) continue;
                grid[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
        if (!q.empty()) time++;
    }

    return (totalOranges == rottenOranges) ? time : -1;
}