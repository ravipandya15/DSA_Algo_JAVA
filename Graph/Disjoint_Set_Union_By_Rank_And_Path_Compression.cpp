#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
    cout << "Disjoint_Set_Union_By_Rank_And_Path_Compression" << endl;
    int m = 5;
    int parent[100000];
    int rank[100000];
    makeSet(m, parent, rank);
    
    while (m-- > 0)
    {
        int u, v;
        cin >> u >> v;

        Union(u, v, parent, rank);
    }
    
    // if 2 and 3 belongs to same component or not
    if (findParent(2, parent) != findParent(2, parent))
    {
        cout << "diff. component" << endl;
    }
    else
    {
        cout << "Same component" << endl;
    }

    return 0;
}

void makeSet(int size, int parent[], int rank[])
{
    for (int i = 0; i < size; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

// compression 7 -> 6 -> 5 -> 4 -> 3
int findParent(int node, int parent[])
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

void Union(int u, int v, int parent[], int rank[])
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