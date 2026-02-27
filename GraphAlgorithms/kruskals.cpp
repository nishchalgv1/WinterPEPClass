#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

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

bool compare(Edge e1, Edge e2)
{
    return e1.w < e2.w;
}

int main()
{
    int V, E;
    cout << "Enter no of vertices" << endl;
    cin >> V;
    cout << "Enter no of edges: " << endl;
    cin >> E;

    vector<Edge> edges;
    for (int i = 0; i < E; ++i)
    {
        int u, v, w;
        cout << "Enter u, v and w: " << endl;
        cin >> u >> v >> w;
        Edge e(u, v, w);
        edges.push_back(e);
    }

    // sort edges acc to weight
    sort(edges.begin(), edges.end(), compare);

    int mstWeight = 0;
    vector<Edge> mstEdges;
    DSU dsu(6);
    for (int i = 0; i < edges.size(); ++i)
    {
        int src = edges[i].u;
        int dest = edges[i].v;
        int weight = edges[i].w;

        // cycle detection
        if (dsu.findParent(src) != dsu.findParent(dest))
        {
            dsu.unionByRank(src, dest);
            Edge currEdge(src, dest, weight);
            mstEdges.push_back(currEdge);
            mstWeight += weight;
        }
    }

    for (int i = 0; i < mstEdges.size(); ++i)
    {
        Edge curr = mstEdges[i];
        int src = curr.u;
        int dest = curr.v;
        int weight = curr.w;
        cout << src << "->" << dest << "weight: " << weight << endl;
    }
    cout << "Mst weight: " << mstWeight << endl;
}