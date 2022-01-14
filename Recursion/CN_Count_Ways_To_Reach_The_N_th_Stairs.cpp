#include<iostream>
#include<vector>
using namespace std;

int main()
{
    cout << "CN_Count_Ways_To_Reach_The_N_th_Stairs.cpp";
    return 0;
}

// famous question -> Adobe, Microsoft, Morgan Stanley, Expedia group
// will give TLE -> need to do DP.
int countDistinctWayToClimbStair(long long nStairs)
{
    if (nStairs < 0) return 0;
    if (nStairs == 0) return 1;
    return countDistinctWayToClimbStair(nStairs - 1) + countDistinctWayToClimbStair(nStairs - 2);
}