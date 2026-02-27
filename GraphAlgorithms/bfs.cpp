#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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
    }

    vector<bool> visited(V + 1);
    bfs(adj, 0, visited);
}