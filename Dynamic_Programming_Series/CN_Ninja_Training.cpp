#include<vector>
#include<iostream>
using namespace std;

int main()
{
    return 0;
}

int solve(int day, int last, vector<vector<int>> &points)
{
    if (day == 0)
    {// means day 0
        // compute best ans
        int maxi = 0;
        for (int i = 0; i <= 2; i++)
        {
            if (i != last)
            {
                maxi = max(maxi, points[0][i]);
            }
        }
        return maxi;
    }

    int maxi = 0;
    for (int i = 0; i <= 2; i++)
    {
        if (i != last)
        {
            int activity = points[day][i] + solve(day - 1, i, points);
            maxi = max(maxi, activity);
        }
    }

    return maxi;
}

// Recursion
int ninjaTraining1(int n, vector<vector<int>> &points) {
    return solve(n-1, 3, points);
}


int solve1(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (dp[day][last] != -1) return dp[day][last];

    if (day == 0)
    {// means day 0
        // compute best ans
        int maxi = 0;
        for (int i = 0; i <= 2; i++)
        {
            if (i != last)
            {
                maxi = max(maxi, points[0][i]);
            }
        }
        return dp[day][last] = maxi;
    }

    int maxi = 0;
    for (int i = 0; i <= 2; i++)
    {
        if (i != last)
        {
            int activity = points[day][i] + solve1(day - 1, i, points, dp);
            maxi = max(maxi, activity);
        }
    }

    return dp[day][last] = maxi;
}

// Memoization
// TC -> O(N*4*3)
// SC -> O(N) + O(N*4)
int ninjaTraining2(int n, vector<vector<int>> &points) {
    vector<vector<int>> dp(n, vector<int> (4, -1));
    return solve1(n-1, 3, points, dp);
}

// Tabulation
// TC -> O(N*4*3)
// SC -> O(N*4)
int ninjaTraining3(int n, vector<vector<int>> &points) {
    vector<vector<int>> dp(n, vector<int> (4, 0));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]); 
    dp[0][2] = max(points[0][0], points[0][1]); 
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2])); 

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;

            for(int task = 0; task <= 2; task++)
            {
                if (task != last)
                {
                    int activity = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], activity);
                }
            }
        }
    }

    return dp[n-1][3];
}

// Space Optimization
// TC -> O(N*4*3)
// SC -> O(4)
int ninjaTraining4(int n, vector<vector<int>> &points) {

    vector<int> prev(4, 0);

    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]); 
    prev[2] = max(points[0][0], points[0][1]); 
    prev[3] = max(points[0][0], max(points[0][1], points[0][2])); 

    for (int day = 1; day < n; day++)
    {
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++)
        {
            temp[last] = 0;

            for(int task = 0; task <= 2; task++)
            {
                if (task != last)
                {
                    int activity = points[day][task] + prev[task];
                    temp[last] = max(temp[last], activity);
                }
            }
        }
        prev = temp;
    }

    return prev[3];
}
