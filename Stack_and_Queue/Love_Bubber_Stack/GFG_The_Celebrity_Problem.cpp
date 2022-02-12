#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{
    cout << "GFG_The_Celebrity_Problem";
}

class Solution 
{
    private:
    bool knows(int a, int b, vector<vector<int> >& M, int n)
    {
        if (M[a][b] == 1) return true;
        return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // step 1 -> push all indexes in Stack
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            st.push(i);
        }

        // step 2
        while (st.size() > 1)
        {
            int a = st.top();
            st.pop();

            int b = st.top();
            st.pop();

            if (knows(a, b, M, n))
            {
                // ingore a and push b
                st.push(b);
            }
            else{
                st.push(a);
            }
        }

        // now only 1 element is there in stack whih might be Potential solution
        // verify
        int ans = st.top();
        int rowCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (M[ans][i] == 0) rowCount++;
        }

        if (rowCount != n) return -1;

        int colCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (M[i][ans] == 1) colCount++;
        }

        if (colCount != n-1) return -1;
        return ans;
    }
};