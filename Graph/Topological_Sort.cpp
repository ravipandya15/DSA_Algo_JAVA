#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    cout << "Topological Sorting usinf DFS and BFS(Kahn's Algorithm)" << endl;
    return 0;
}

// DFS
// TC -> O(N + E)
// SC -> O(N+E) + O(N) + O(N) + O(N)
void findTopoSort(int node, stack<int> st, vector<int> visited, vector<int> adj[])
{
    visited[node] = 1;

    for (auto it : adj[node])
    {
        if (visited[it] == 0)
        {
            findTopoSort(it, st, visited, adj);
        }
    }

    st.push(node);
}

vector<int> topoSort1(int V, vector<int> adj[])
{
    stack<int> st;
    vector<int> visited(V, 0); // considering 0 based indexing

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            findTopoSort(i, st, visited, adj);
        }
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

// Kahn's Algorithm
// BFS
// TC -> O(N + E)
// SC -> O(N+E) + O(N) + O(N) + O(N) 
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> ans(V, 0);
    int index = 0;
    while (!q.empty())
    {
        int node = q.front();
        ans[index++] = node;
        q.pop();

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    return ans;
}