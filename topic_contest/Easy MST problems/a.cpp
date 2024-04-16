#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 5;
int parent[maxn];
int sz[maxn];

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
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
    int n; cin >> n;
    pair<int, int> p[n];
    for(int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;

    int cost = 0;
    const int INF = 1e9;

    vector<int> dis(n, INF);
    vector<bool> vis(n, false);
    
    dis[0] = 0;

    for(int i = 0; i < n; i++) {
        int v = -1;

        for(int j = 0; j < n; j++) {
            if(!vis[j] and (v == -1 or dis[j] < dis[v])) {
                v = j;
            }
        }

        cost += dis[v];
        vis[v] = 1;

        for(int to = 0; to < n; to++) {
            int curr = abs(p[v].first - p[to].first) + abs(p[v].second-p[to].second);

            if(curr < dis[to]) {
                dis[to] = curr;
            }
        }

    }

    cout << 2 * cost << "\n";

    return 0;
}
