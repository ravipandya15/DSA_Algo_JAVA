#include<iostream>
#include<stack>
using namespace std;

int main()
{
    cout << "CN_Design_Special_Stack_Problem";
}

class SpecialStack {
    stack<int> st;
    int mini; // here mini = INT_MAX will work but it's not required as in push operation for 1st element we are updating mini.

    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
        // for 1st element
        if (st.empty())
        {
            st.push(data);
            mini = data;
        }
        else
        {
            if (data < mini)
            {
                int val = 2*data - mini;
                st.push(val);
                mini = data;
            }
            else
            {
                st.push(data);
            }
        }
    }

    int pop() {
        // underflow condition
        if (st.empty()) return -1;

        int cur = st.top();
        st.pop();
        if (cur > mini)
        {
            return cur;
        }
        else
        {
            int prevMin = mini;
            int val = 2*mini - cur;
            mini = val;
            return prevMin;
        }
    }

    int top() {
        if (st.empty()) return -1;

        int cur = st.top();
        if (cur < mini)
        {
            return mini;
        }
        else
        {
            return cur;
        }
    }

    bool empty() {
        return st.empty();
    }

    int getMin() {
        if (st.empty()) return -1;
		return mini;
    }  
};