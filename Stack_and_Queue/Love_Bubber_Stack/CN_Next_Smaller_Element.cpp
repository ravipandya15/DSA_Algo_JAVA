#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{
    cout << "CN_Next_Smaller_Element";
}

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int cur = arr[i];
        while (st.top() >= cur)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(cur);
    }
    return ans;
}