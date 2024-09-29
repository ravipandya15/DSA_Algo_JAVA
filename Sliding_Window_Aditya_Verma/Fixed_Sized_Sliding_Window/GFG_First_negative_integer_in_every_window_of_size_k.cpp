#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    return 0;
}

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    vector<long long> ans;
    deque<long long> deque;
    int i = 0;
    int j = 0;

    while (j < N)
    {
        // calculation
        if (A[j] < 0)
        {
            deque.push_back(A[j]);
        }

        if (j-i+1 < K)
        {
            j++;
        }
        else if (j - i + 1 == K)
        {
            // ans from calculation
            if (deque.empty())
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(deque.front());
            }


            // slide the window
            if (A[i] == deque.front())
            {
                deque.pop_front();
            }

            j++;
            i++;
        }
    }

    return ans;
}
