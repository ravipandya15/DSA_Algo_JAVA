#include<iostream>
#include<vector>
using namespace std;

int main()
{
    cout << "Rat_in_a_Maze_Problem_I.cpp";
    return 0;
}

class Solution{
    private:

    // Approach 2
    void solve1(vector<vector<int>>& m, int n, int x, int y, vector<int> dx, vector<int> dy, 
                                string ans, vector<string>& result, vector<vector<int>>& visited)
    {
        // base case
        if (x == n-1 && y == n-1)
        {
            result.push_back(ans);
            return;
        }

        // lexicographical order > DLRU

        string dir = "DLRU";
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (isSafe(newX, newY, m, n, visited))
            {
                visited[x][y] = 1;
                solve1(m, n, newX, newY, dx, dy, ans + dir[i], result, visited);
                visited[x][y] = 0;
            }
        }
    }

    bool isSafe(int newX, int newY, vector<vector<int>> &m, int n, vector<vector<int>>& visited)
    {
        if (newX >= 0 && newX < n && newY >= 0 && newY < n && m[newX][newY] == 1 && visited[newX][newY] == 0)
        {
            return true;
        }
        return false;
    }

    // Approach - 1
    void solve(vector<vector<int>> &m, int n, int x, int y, string ans, vector<string>& result, 
                vector<vector<int>>& visited)
    {
        // base case
        if (x == n-1 && y == n-1)
        {
            result.push_back(ans);
            return;
        }

        // now you are at x,y
        visited[x][y] = 1;

        // lexicographical order > DLRU

        // down
        int newX = x + 1;
        int newY = y;
        if (isSafe(newX, newY, m, n, visited))
        {
            solve(m, n, newX, newY, ans + "D", result, visited);
        }

        // left
        newX = x;
        newY = y - 1;
        if (isSafe(newX, newY, m, n, visited))
        {
            solve(m, n, newX, newY, ans + "L", result, visited);
        }

        // right
        newX = x;
        newY = y + 1;
        if (isSafe(newX, newY, m, n, visited))
        {
            solve(m, n, newX, newY, ans + "R", result, visited);
        }

        // Up
        newX = x - 1;
        newY = y;
        if (isSafe(newX, newY, m, n, visited))
        {
            solve(m, n, newX, newY, ans + "U", result, visited);
        }

        // back-tracking
        visited[x][y] = 0;
    }
    public:
    // Approach 1
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> result;
        if (m[0][0] == 0)
            return result;

        vector<vector<int>> visited = m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visited[i][j] = 0;
            }
        }
        int x = 0, y = 0;
        string ans = "";
        solve(m, n, x, y, ans, result, visited);
        return result;
    }

    // Approach 2
    vector<string> findPath1(vector<vector<int>> &m, int n) {
        vector<string> result;
        if (m[0][0] == 0)
            return result;

        vector<vector<int>> visited = m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visited[i][j] = 0;
            }
        }
        int x = 0, y = 0;
        vector<int> dx = {1, 0, 0, -1};
        vector<int> dy = {0, -1, 1, 0};
        string ans = "";
        solve1(m, n, x, y, dx, dy, ans, result, visited);
        return result;
    }
};