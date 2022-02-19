#include<iostream>
#include<queue>
#include<stack>
#include<unordered_map>
using namespace std;

int main()
{
    return 0;
}

string FirstNonRepeating(string A){
    string sb = "";
    queue<char> q;
    unordered_map<char, int> count;

    for (int i = 0; i < A.length(); i++)
    {
        count[A[i]]++;

        // add it in queue
        q.push(A[i]);

        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                sb.push_back(q.front());
                break;
            }
        }

        if (q.empty())
        {
            sb.push_back('#');
        }
    }

    return sb;
}
