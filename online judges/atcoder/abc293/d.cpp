#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

int parent[maxn], sz[maxn];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main() {
    int n, m; cin >> n >> m;

    vector<bool> used(n, 0);

    int ans = 0;

    for(int i = 0; i < n; i++)
        make_set(i);

    for(int i = 0; i < m; i++) {
        int u, v; char c;
        cin >> u >> c >> v >> c;
        u--; v--;

        u = find_set(u);
        v = find_set(v);
        if(u == v) {
            ans++;
            used[u] = 1;
        }
        else {
            union_sets(u, v);
        }
    }


    int no_ans = 0;
    for(int i = 0; i < n; i++) {
        int j = find_set(i);
        if(used[j]) continue;
        else {
            no_ans++;
            used[j] = 1;
        }
    }

    cout << ans << " " << no_ans << "\n";

    return 0;
}
