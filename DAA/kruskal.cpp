#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dest, weight;
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int v, vector<int> &parent) {
    if (v == parent[v]) return v;
    return parent[v] = findParent(parent[v], parent);
}

void unionSets(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (rank[u] < rank[v]) parent[u] = v;
    else if (rank[u] > rank[v]) parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}

int main() {
    int V = 7;
    vector<Edge> edges = {
        Edge(0, 1, 4), Edge(0, 2, 2), Edge(0, 3, 0),
        Edge(1, 3, 5), Edge(2, 3, 3), Edge(2, 4, 3), Edge(3, 4, 1)
    };

    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; i++) parent[i] = i;

    cout << "Edge: Weight\n";
    int count = 0, total = 0;

    for (Edge e : edges) {
        if (count == V - 1) break;
        int u = findParent(e.src, parent);
        int v = findParent(e.dest, parent);

        if (u != v) {
            cout << e.src << "-" << e.dest << ":" << e.weight << endl;
            total += e.weight;
            unionSets(u, v, parent, rank);
            count++;
        }
    }

    cout << "Total Weight of MST = " << total << endl;
    return 0;
}
// Edge: Weight
// 0-3:0
// 3-4:1
// 0-2:2
// 0-1:4
// Total Weight of MST = 7
