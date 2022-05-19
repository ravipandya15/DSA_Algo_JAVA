#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
typedef long long ll;

int main()
{
    return 0;
}

vector<int> findNextSmallerElement(vector<int>& heights, int n)
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

vector<int> findPreviousSmallerElement(vector<int>& heights, int n)
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


int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
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

int maximalRectangle(vector<vector<char>>& matrix) {
    int maxAns = 0;
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> height(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 1) height[j]++;
            else height[j] = 0;
        }
        int area = largestRectangleArea(height);
        maxAns = max(maxAns, area);
    }
    return maxAns;
}