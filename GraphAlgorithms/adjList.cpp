#include <bits/stdc++.h>
using namespace std;

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

    // print adj list
    for(int i = 0; i <= V; ++i){
        cout << "Adjacent neighbors to i: " << i << "->";
        for(int j = 0; j < adj[i].size(); ++j){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

}