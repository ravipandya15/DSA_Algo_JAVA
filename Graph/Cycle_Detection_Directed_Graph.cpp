#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    cout << "Cycle_Detection_Directed_Graph Using BFS and DFS";
    return 0;
}

// Kahn's Algorithm (BFS)
// TC -> O(N+E)
// SC -> O(N+E) + O(N) + O(N)
bool isCycle_BFS(int V, vector<int> adj[])
{
    queue<int> q;
    vector<int> inDegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (int it : adj[i])
        {
            inDegree[it]++;
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    int count = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;

        for (int it : adj[node])
        {
            inDegree[it]--;
            if (inDegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    if (count == V) return false; // as topological sort is possible, so there will not be any clcle in graph
    return true;
}


// DFS
// TC -> O(N+E)
// SC -> O(N+E) + O(N) + O(N)
bool checkForCycle_DFS(int node, vector<int>& vis, vector<int>& dfsVis, vector<int> adj[])
{
    vis[node] = 1;
    dfsVis[node] = 1;

    for (auto it : adj[node])
    {
        if (vis[it] == 0)
        {
            if (checkForCycle_DFS(it, vis, dfsVis, adj)) return true;
        }
        else if (dfsVis[it] == 1) return true;
    }

    dfsVis[node] = 0;
    return false;
}

bool isCycle_DFS(int V, vector<int> adj[])
{
    // 0 based indexing
    // int vis[V], dfsVis[V]; 
    // memset(vis, 0, sizeof vis); 
    // memset(dfsVis, 0, sizeof dfsVis); 
    vector<int> vis(V, 0);
    vector<int> dfsVis(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0)
        {
            if (checkForCycle_DFS(i, vis, dfsVis, adj)) return true;
        }
    }
    return false;
}