#include<iostream>
#include<stack>
using namespace std;

int main()
{
    return 0;
}

class MinStack {
    long long mini;
    stack<long long> st;
    public:
    MinStack() {
        mini = LONG_MAX;
    }
    
    void push(int value) {
        long val = value;
        if (st.size() == 0)
        {
            // first element
            mini = val;
            st.push(val);
        }
        else
        {
            if (val < mini)
            {
                // update mini and push modified value
                st.push(2 * val - mini);
                mini = val;
            }
            else
            {
                st.push(val);
            }
        }
    }
    
    void pop() {
        if (st.size() == 0) return;
        long val = st.top();
        st.pop();

        if (val < mini)
        {
            // it means it's modified value so roll back mini to prevMin.
            mini = 2 * mini - val;
        }
    }
    
    int top() {
        long val = st.top();

        if (val < mini)
        {
            return mini;
        }
        return val;
    }
    
    int getMin() {
        return mini;
    }
};

