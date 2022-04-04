#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minimumDays(int S, int N, int M){
    int days = 0;
    
    if ( (M > N) || ( (N * 6 < M * 7) && (S > 6) ) )
    {
        return -1;
    }
    else
    {
        days = (M * S)/ N;
        if ( ((M * S) % N) != 0 )
        {
            days++;
        }
    }
    
    return days;
}