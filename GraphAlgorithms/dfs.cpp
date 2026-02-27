#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int sv, vector<bool> &visited){
    cout << sv << " ";
    visited[sv] = true;

    // print all adjacent neighbors of sv
    for(int i = 0; i < adj[sv].size(); ++i){
        int neighbor = adj[sv][i];
        if(!visited[neighbor]){
            dfs(adj, neighbor, visited);
        }
    }
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
    dfs(adj, sv, visited);
}