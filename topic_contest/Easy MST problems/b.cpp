#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

int parent[maxn], sz[maxn];

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if(v == parent[v]) 
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if(a != b) {
        if(sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

struct Edge {
    int from, to, w;

    bool operator<(const Edge& o) {
        return w < o.w;
    }
};

int main() {
    int n, m; cin >> n >> m;
    vector<Edge> edges;
    for(int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        a--; b--;
        edges.push_back({a, b, w});
    }

    sort(edges.begin(), edges.end());

    int cost = 0;
    vector<pair<int, int>> result;

    for(int i = 0; i < n; i++) make_set(i);

    for(auto e : edges) {
        if(find_set(e.from) != find_set(e.to)) {
            cost += e.w;
            union_sets(e.from, e.to);
            result.push_back({e.from+1, e.to+1});
        }
    }

    cout << cost << "\n";
    cout << result.size() << "\n";
    for(auto e : result) cout << e.first << " " << e.second << "\n";

    return 0;
}
