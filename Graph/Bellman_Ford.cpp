#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node
{
    int u; 
    int v;
    int weight;
    node(int _v, int _u, int _w)
    {
        v = _v;
        u = _u;
        weight = _w;
    }
};

int main(){
    int N,m;
    cin >> N >> m;
    vector<node> edges; 
    for(int i = 0;i<m;i++) {
        int u, v, wt;
        cin >> u >> v >> wt; 
        edges.push_back(node(u, v, wt)); 
    }

    int src;
    cin >> src; 


    int inf = 10000000; 
    vector<int> dist(N, inf); 

    dist[src] = 0; 

    for(int i = 1;i<=N-1;i++) {
        for(auto it: edges) {
            if(dist[it.u] + it.weight < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.weight; 
            }
        }
    }

    int fl = 0; 
    for(auto it: edges) {
        if(dist[it.u] + it.weight < dist[it.v]) {
            cout << "Negative Cycle"; 
            fl = 1; 
            break; 
        }
    }

    if(!fl) {
        for(int i = 0;i<N;i++) {
            cout << i << " " << dist[i] << endl;
        }
    }


    return 0;
}