#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{
    return 0;
}

// Approach - 1
// TC -> O(N)
// SC -> O(N)
bool validateStackSequences_1(vector<int>& pushed, vector<int>& popped) {
    stack<int> st;
    for (int i = 0, j = 0; i < pushed.size(); i++)
    {
        st.push(pushed[i]);
        while (!st.empty() && st.top() == popped[j])
        {
            st.pop();
            j++;
        }
    }
    
    return st.size() == 0;
}

// Approach - 2 -> used pushed array as stack (consider pushed array as stack)
// TC -> O(N)
// SC -> O(1)
bool validateStackSequences_2(vector<int>& pushed, vector<int>& popped) {
    int i = 0, j = 0;
    for (int x : pushed)
    {
        pushed[i] = x;
        i++;
        while (i > 0 && pushed[i-1] == popped[j])
        {
            i--;
            j++;
        }
    }
    return i == 0;
}