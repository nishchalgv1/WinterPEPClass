#include <bits/stdc++.h>
using namespace std;

int main(){
    // V -> vertices
    // E -> edges
    int V, E;
    cout << "Enter no of vertices: " << endl;
    cin >> V;
    cout << "Enter no of edges: " << endl;
    cin >> E;

    // create a matrix of size V * V
    vector<vector<int>> matrix(V + 1, vector<int>(V + 1, 0)); // 0 -> false;

    for(int i = 1; i <= E; ++i){
        int u, v;
        cin >> u >> v;
        matrix[u][v] = 1; 
        matrix[v][u] = 1; //  not applicable for directed graph
    }

    // print adjacency matrix
    for(int i = 1; i <= V; ++i){
        for(int j = 1; j <= V; ++j){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}