#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Node
{
    int u; 
    int v;
    int weight;
    Node(int _v, int _u, int _w)
    {
        v = _v;
        u = _u;
        weight = _w;
    }
};

bool compare(Node n1, Node n2)
{
    return n1.weight < n2.weight;
}

void makeSet(int size, vector<int> parent, vector<int> rank)
{
    for (int i = 0; i < size; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

// compression 7 -> 6 -> 5 -> 4 -> 3
int findParent(int node, vector<int> parent)
{
    if (node == parent[node])
    {
        return node;
    }

    // storing in parent[node] is path compression 
    return parent[node] = findParent(parent[node], parent);

    // or we can write like this
    //parent[node] = findParent(parent[node], parent);
    //return parent[node];
}

void Union(int u, int v, vector<int> parent, vector<int> rank)
{
    int i = findParent(u, parent);
    int j = findParent(v, parent);

    // if both i and i are in same set
    if (i == j) return;

    if (rank[i] < rank[j])
    {
        parent[i] = j;
    }
    else if (rank[j] < rank[i])
    {
        parent[j] = i;
    }
    else
    {// means rank of i and j are same
        parent[j] = i;
        rank[i]++;
    }
}

void kruskal_Algo(int N, vector<Node> adj)
{
    sort(adj.begin(), adj.end(), compare);
    vector<int> parent(N);
    vector<int> rank(N);

    makeSet(N, parent, rank);

    int cost = 0;
    vector<Node> mst;

    for (auto it : adj)
    {
        if (findParent(it.u, parent) != findParent(it.v, parent))
        {
            cost += it.weight;
            mst.push_back(it);
            Union(it.u, it.v, parent, rank);
        }
    }

    cout << "Cost of spanning tree is " << cost << endl;
    for (auto it : mst)
    {
        cout << it.u << "--->" << it.v << endl;
    }
}


int main()
{
    cout << "Kruskal_Algorithm" << endl;
    int n = 5; // size of nodes

    vector<Node> adj;
    adj.push_back(Node(0, 1, 2));
    adj.push_back(Node(0, 3, 6));
    adj.push_back(Node(1, 3, 8));
    adj.push_back(Node(1, 2, 3));
    adj.push_back(Node(1, 4, 5));
    adj.push_back(Node(2, 4, 7));

    kruskal_Algo(n, adj);
    return 0;
}