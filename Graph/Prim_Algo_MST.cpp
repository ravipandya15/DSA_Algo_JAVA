#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<iostream>
#include<functional>
using namespace std;

int main()
{
    cout << "Prim_Algo_MST.cpp";
    return 0;
}

// TC -> O((N + E) + NLogN)
// efficient
void primAlgo_Efficient(int N, vector<pair<int, int>> adj[])
{
    vector<int> key;
    vector<bool> mst;
    vector<int> parent;

    // initialization
    for (int i = 0; i < N; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }


    // check this
    // priority_queue<pair<int, int>, vector<int, int>, std::greater<pair<int, int>>> pq;
    // above one is correct but giving error
    priority_queue<pair<int, int>> pq;

    key[0] = 0;
    parent[0] = -1; // as 0 does not have any parent
    pq.push({0,0});
    // as MST Contains V-1 Edges
    while (!pq.empty())
    {
        int u = pq.top().first;
        pq.pop();

        mst[u] = true;

        for (auto it : adj[u])
        {
            if (mst[it.first] == false && it.second < key[it.first])
            {
                key[it.first] = it.second;
                parent[it.first] = u;
                pq.push({it.first, key[it.first]});
            }
        }

        for (int i = 1; i < N; i++)
        {
            cout << parent[i] << "--->" << i << endl;
        }
    }
}
// TC -> O(N) + O((N*N) + (N + E))
// brute force
void primAlgo_BruteForce(int N, vector<pair<int, int>> adj[])
{
    vector<int> key;
    vector<bool> mst;
    vector<int> parent;

    // initialization
    for (int i = 0; i < N; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    key[0] = 0;
    parent[0] = -1; // as 0 does not have any parent
    // as MST Contains V-1 Edges
    for (int i = 0; i < N-1; i++)
    {
        int u = 0;
        int mini = INT_MAX;
        // find min. value from Key array
        for (int v = 0; v < N; i++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                mini = key[v];
                u = v;
            }
        }

        mst[u] = true;

        for (auto it : adj[u])
        {
            if (mst[it.first] == false && it.second < key[it.first])
            {
                key[it.first] = it.first;
                parent[it.first] = u;
            }
        }
    }

    for (int i = 1; i < N; i++)
    {
        cout << parent[i] << "--->" << i << endl;
    }
}
