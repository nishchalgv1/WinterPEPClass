#include <bits/stdc++.h>
using namespace std;

bool hasPath(vector<int> adj[], int src, int dest, vector<bool> &visited){
    if(src == dest) return true;
    visited[src] = true;

    // print all adjacent neighbors of sv
    for(int i = 0; i < adj[src].size(); ++i){
        int neighbor = adj[src][i];
        if(!visited[neighbor]){
            if(hasPath(adj, neighbor, dest, visited)){
                return true;
            }
        }
    }
    return false;
}

int main(){
     int V, E;
    cout << "Enter V: " << endl;
    cin >> V;
    cout << "Enter E: " << endl;
    cin >> E;

    vector<int> adj[V + 1];
    
    // take edges input
    for(int i = 1; i <= E; ++i){
        int u, v;
        cout << "Enter u and v: " << endl;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int sv = 1;
    vector<bool> visited(V + 1, false);
    bool output = hasPath(adj, 0, 4, visited);
    if(output == true){
        cout << "Path exists" << endl;
    }else{
        cout << "No path" << endl;
    }
}