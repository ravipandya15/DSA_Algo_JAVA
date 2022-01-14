#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    return 0;
}

void DFS(int node, vector<bool> visited, vector<int> adj[], vector<int> dfs)
{
    dfs.push_back(node);
    visited[node] = true;

    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            DFS(it, visited, adj, dfs);
        }
    }
}

vector<int> DFSTraversal(int V, vector<int> adj[])
{
    vector<int> dfs;
    vector<bool> visited(V+1, 0);

    for (int i = 1; i <= V; i++)
    {
        if (!visited[i])
            DFS(i, visited, adj, dfs);
    }

    return dfs;
}