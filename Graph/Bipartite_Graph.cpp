#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
   cout << "Bipartite using BFS and DFS" << endl;
    return 0;
}



// BFS
// TC > O(N+E)
// SC -> O(N+E) + O(N) + O(N)
bool checkBFS(int node, vector<int>& color, vector<int> adj[])
{
    queue<int> q;
    q.push(node);
    color[node] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto it : adj[cur])
        {
            if (color[it] == -1)
            {
                q.push(it);
                color[it] = 1 - color[cur];
            }
            else if (color[it] == color[cur])
            {
                return false;
            }
        }
    }

    return true;
}

bool checkBipartite1(int V, vector<int> adj[])
{
    // this time it's 0 based indexing
    vector<int> color;
    for (int i = 0; i < V; i++)
    {
        color[i] = -1;
    }

    // check for every component
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (checkBFS(i, color, adj) == false)
            {
                return false;
            }
        }
    }

    return true;
}


// DFS
// TC > O(N+E)
// SC -> O(N+E) + O(N) + O(N)
bool checkDFS(int node, vector<int>& color, vector<int> adj[])
{
    if (color[node] == -1)
        color[node] = 1;

    for (auto it : adj[node])
    {
        if (color[it] == -1)
        {
            color[it] = 1 - color[node];
            if (!checkDFS(it, color, adj)) return false;
        }
        else if (color[it] == color[node]) return false;
    }
    return true;
}

bool checkBipartite(int V, vector<int> adj[])
{
    // this time it's 0 based indexing
    vector<int> color;
    for (int i = 0; i < V; i++)
    {
        color[i] = -1;
    }

    // check for every component
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (checkBFS(i, color, adj) == false)
            {
                return false;
            }
        }
    }

    return true;
}