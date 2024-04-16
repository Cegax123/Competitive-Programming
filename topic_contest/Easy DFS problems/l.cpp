#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5+5;
vector<int> adj[maxn];
int dis[maxn];

void allice(int v, int p=-1) {
    if(p == -1) dis[v] = 0;
    else dis[v] = dis[p] + 1;

    for(int to : adj[v]) if(to != p) {
        allice(to, v);
    }
}

int h[maxn];
int marked[maxn];
int furthest[maxn];

void dfs(int v, int p=-1) {
    if(p == -1) h[v] = 0;
    else h[v] = h[p] + 1;

    for(int to : adj[v]) if(to != p) {
        dfs(to, v);
    }
}

int ans = 0;
int x;

void bob(int v, int p=-1) {
    furthest[v] = v;

    for(int to : adj[v]) if(to != p) {
        bob(to, v);

        if(!marked[to]) {
            if(h[furthest[to]] > h[furthest[v]]) furthest[v] = furthest[to];
        }
        else marked[v] = 1;
    }


    if(marked[v] and h[v] * 2 < h[0]) {
        ans = max(ans, dis[furthest[v]]);
    }
}

int main() {
    int n; cin >> n >> x;
    x--;

    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    allice(0);
    dfs(x);

    marked[0] = 1;

    bob(x);

    cout << 2 * ans << "\n";

    return 0;
}
