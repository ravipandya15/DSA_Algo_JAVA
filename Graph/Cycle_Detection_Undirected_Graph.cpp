#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    cout << "Cycle_Detection_Undirected_Graph Using BFS and DFS";
    return 0;
}

// BFS
// TC -> O(N+E)
// SC -> O(N+E) + O(N) + O(N)
bool checkForCycle(int i, vector<int> visited, vector<int> adj[])
{
    queue<pair<int, int>> q; // BFS
    q.push({i, -1});
    visited[i] = true;

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                q.push({it, node});
                visited[it] = true;
            }
            else
            {// means it is visited so check is it is parent or not
                if (it != parent) return true;
            }
        }
    }


    return false;
}

bool isCycle_BFS(int V, vector<int> adj[])
{
    vector<int> visited(V+1, 0);
    for (int i = 1; i <= V; i++)
    {
        if (!visited[i])
        {
            if (checkForCycle(i, visited, adj)) return true;
        }
    }

    return false;
}


// DFS
// TC -> O(N+E)
// SC -> O(N+E) + O(N) + O(N)
bool checkForCycle_DFS(int node, int parent, vector<int> visited, vector<int> adj[])
{
    visited[node] = 1;

    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            if (checkForCycle_DFS(it, node, visited, adj)) return true;
        }
        else
        {
            if (it != parent) return true;
        }
    }
    return false;
}


bool isCycle_DFS(int V, vector<int> adj[])
{
    vector<int> visited(V+1, 0);
    for (int i = 1; i <= V; i++)
    {
        if (!visited[i])
        {
            if (checkForCycle_DFS(i, -1, visited, adj)) return true;
        }
    }

    return false;
}
