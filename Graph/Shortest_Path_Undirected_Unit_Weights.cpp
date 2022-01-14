#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    cout << "Shortest_Path_Undirected_Unit_Weights";
    return 0;
}

void ShortestPath(int N, int src, vector<int> adj[])
{
    vector<int> dist(N);
    for (int i = 0; i < N; i++)
    {
        dist[i] = INT_MAX;
    }

    queue<int> q;
    dist[src] = 0;
    q.push(src);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int it : adj[node])
        {
            if (dist[node] + 1 < dist[it])
            {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << dist[i] <<  " " << endl;
    }
}