// Task: Check whether the graph is connected or not
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int sv, vector<bool> &visited){
    cout << sv << " ";
    visited[sv] = true;

    for(auto neighbor: adj[sv]){
        if(!visited[neighbor]){
            dfs(adj, neighbor, visited);
        }
    }
}

void bfs(vector<int> adj[], int sv, vector<bool>& visited){
    queue<int> pendingNeighbors;
    pendingNeighbors.push(sv);
    visited[sv] = true;

    while(!pendingNeighbors.empty()){
        int front = pendingNeighbors.front();
        pendingNeighbors.pop();

        cout << front << " ";

        for(int i = 0; i < adj[front].size(); ++i){
            int neighbor = adj[front][i];

            if(!visited[neighbor]){
                visited[neighbor] = true;
                pendingNeighbors.push(neighbor);
            }
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
        //cout << "i: " << i << endl;
    }

    vector<bool> visited(V + 1, false);
    int components = 0;
    bool isConnected = true; // assume graph is connected
    for(int i = 1; i <= V; ++i){
        if(!visited[i]){
            //dfs(adj, i, visited);
            bfs(adj, i, visited);
            //isConnected = false;
            cout << endl;
            components++;
        };
    }
    cout << "Total Components: " << components << endl;
    if(components == 1){
        cout << "Yes graph is connected! " << endl;
    }else cout << "No" << endl;

    // if(isConnected == true) cout << "it is connected "<< endl;
    // else cout << "Not connected" << endl;
}