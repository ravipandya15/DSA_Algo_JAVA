#include<iostream>
#include<queue>
using namespace std;

int main()
{
    return 0;
}

vector<long long> printFirstNegativeint(long long int A[],
                                             long long int N, long long int K) {
    deque<int> deque;
    vector<long long> ans;

    // for 1st K sized window
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            deque.push_back(i);
        }
    }

    // store ans for 1st window
    if (!deque.empty())
    {
        ans.push_back(A[deque.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    // for remaining K sized Window
    for (int i = K; i < N; i++)
    {
        // removal code
        if (!deque.empty() && i - deque.front() >= K)
        {
            deque.pop_front();
        }

        // adding code
        if (A[i] < 0)
        {
            deque.push_back(i);
        }

        // store ans
        if (!deque.empty())
        {
            ans.push_back(A[deque.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;                                          
}