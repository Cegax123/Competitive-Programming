#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
vector<int> adj[maxn];
int col[maxn];

int cnt = 0;

void dfs(int v) {
    col[v] = 1;
    for(int to : adj[v]) {
        if(col[to] == 0) {
            dfs(to);
        }
        else if(col[to] == 1) {
            cnt++;
        }
    }
    col[v] = 2;
}

int main() {
    int p, k; cin >> p >> k;

    for(int i = 1; i <= p; i++) {
        int nxt = (i * 1ll * k) % p;
        if(nxt) {
            adj[i].push_back(nxt);
        }
    }

    for(int i = 0; i < p; i++) {
        if(col[i] == 0) dfs(i);
    }
    cout << cnt << "\n";

    return 0;
}
