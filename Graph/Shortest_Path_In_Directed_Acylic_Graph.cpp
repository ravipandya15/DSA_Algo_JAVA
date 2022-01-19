#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int main()
{
    cout << "Shortest_Path_In_Directed_Acylic_Graph";
    return 0;
}

void findTopologicalSort(int node, vector<int>& visited, stack<int> st, vector<pair<int, int>> adj[])
{
    visited[node] = 1;

    for (auto it : adj[node])
    {
        if (visited[it.first] == 0)
            findTopologicalSort(it.first, visited, st, adj);
    }

    st.push(node);
}

vector<int> shortestPathInDAG(int V, int src, vector<pair<int, int>> adj[])
{
    stack<int> st;
    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            findTopologicalSort(i, visited, st, adj);
        }
    }

    vector<int> dist(V, 0);
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (dist[node] != INT_MAX)
        {
            for (auto it : adj[node])
            {
                if (dist[node] + it.second < dist[it.first])
                {
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }

    return dist;
}