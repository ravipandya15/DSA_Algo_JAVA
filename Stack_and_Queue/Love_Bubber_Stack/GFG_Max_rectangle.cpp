#include<iostream>
#include<stack>
#include<vector>
using namespace std;
#define MAX 1000

int main()
{
    cout << "GFG_Max_rectangle";
}

class Solution{
    private:
    vector<int> findNextSmallerElement(int heights[], int n)
    {
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);

        for (int i = n-1; i >= 0; i--)
        {
            int cur = heights[i];
            while (st.top() != -1 && heights[st.top()] >= cur)
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> findPreviousSmallerElement(int heights[], int n)
    {
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            int cur = heights[i];
            while (st.top() != -1 && heights[st.top()] >= cur)
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }


    int largestRectangleArea(int heights[], int n) {
        vector<int> next = findNextSmallerElement(heights, n);
        vector<int> prev = findPreviousSmallerElement(heights, n);

        int area = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int l = heights[i];
            if (next[i] == -1)
            {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            area = max(area, (l * b));
        }
        return area;
    }

    public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // step 1 -> compute max area for 1st row
        int area = largestRectangleArea(M[0], m);

        // step 2 -> compute max area for remaining row
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (M[i][j] != 0)
                {
                    M[i][j] += M[i-1][j];
                }
                else
                {
                    M[i][j] = 0;
                }
            }

            area = max(area, largestRectangleArea(M[i], m));
        }

        return area;
    }
};
