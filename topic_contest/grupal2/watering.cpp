#include<bits/stdc++.h>
using namespace std;

const int maxn = 305;
int parent[maxn], sz[maxn];

 void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find(int u) {
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void union_set(int u, int v) {
    u = find(u);
    v = find(v);

    if(u != v) {
        if(sz[u] < sz[v]) swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
    }
}

int main() {
    int n; cin >> n;
    int w[n];
    int ans = 0;
    vector<pair<int, pair<int, int>>> edges;
    for(int i = 0; i < n; i++) {
        cin >> w[i];
        make_set(i);

        edges.push_back({w[i], {i, n}});
        edges.push_back({w[i], {n, i}});
    }

    make_set(n);

    int p[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> p[i][j];
            if(i == j) continue;

            edges.push_back({p[i][j], {i, j}});
        }
    }

    sort(edges.begin(), edges.end());

    for(auto e : edges) {
        int c = e.first;

        int u = e.second.first, v = e.second.second;

        int pu = find(u), pv = find(v);


        if(pu != pv) {
            ans += c;
            union_set(u, v);
        }
    }

    cout << ans << "\n";

    return 0;
}
