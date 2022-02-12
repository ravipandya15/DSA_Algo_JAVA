#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{
    cout << "Largest_Rectangle_in_Histogram_84_Love_Bubber";
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