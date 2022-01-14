#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    return 0;
}

vector<int> BFS(int V, vector<int> adj[])
{
    vector<int> bfs;
    vector<int> visited(V+1, 0);

    // loop for every component
    for (int i = 1; i <= V; i++)
    {
        if (visited[i] == 0)
        {

            // bfs
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for (auto it : adj[node])
                {
                    if (!visited[it])
                    {
                        q.push(it);
                        visited[it] = 1;
                    }
                }
            }

        }
    }

    return bfs;
}