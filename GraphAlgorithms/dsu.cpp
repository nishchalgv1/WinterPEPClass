#include <iostream>
#include <vector>
using namespace std;

class DSU
{
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        // for now every vertex is parent of itself
        for (int i = 0; i <= n; ++i)
        {
            parent[i] = i;
        }
    }

    int findParent(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        // parent of u
        int pu = findParent(u);

        // parent of v
        int pv = findParent(v);

        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

int main()
{
    int V, E;
    cout << "Enter V: " << endl;
    cin >> V;
    cout << "Enter E: " << endl;
    cin >> E;

    DSU dsu(V);
    // take edges input
     for(int i = 0; i < E; i++){
        int a, b;
        cin>>a>>b;
        int leaderA= dsu.findParent(a);
        int leaderB= dsu.findParent(b);
        if(leaderA==leaderB){
            cout << "Cycle detected: " << endl;
            cout << a << " " << b << endl;
            return 0;
        }
        else{
            dsu.unionByRank(a, b);
        }
    }

    // for (int i = 0; i <= V; ++i)
    // {
    //     for (int j = 0; j < adj[i].size(); ++j)
    //     {
    //         int u = i;
    //         int v = adj[i][j];
    //         if (!visited[v])
    //         {
    //             visited[v] = true;
    //             if (dsu.findParent(u) == dsu.findParent(v))
    //             {
    //                 cout << "Cycle detected" << endl;
    //                 cout << "u: " << u << endl;
    //                 cout << "v: " << v << endl;
    //                 //return 0;
    //             }
    //             else
    //             {
    //                 dsu.unionByRank(u, v);
    //             }
    //         }
    //     }
    // }
}