#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 100;
const int L = 10;

vector<int> adj[maxn][L];
int cnt;

void insert_edge(int u, int v, int w) {
    while(w >= 10) {
        adj[++cnt][w % 10].push_back(v);
        v = cnt;
        w /= 10;
    }

    adj[u][w].push_back(v);
}

int dis[maxn];
bool vis[maxn];

const int mod = 1e9 + 7;

int main() {
    int n, m; cin >> n >> m;
    cnt = n+1;

    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        insert_edge(u, v, i);
        insert_edge(v, u, i);
    }

    vector<vector<int>> q1, q2;

    dis[1] = 0;
    vis[1] = 1;
    q1.push_back({1});

    while(!q1.empty()) {
        for(auto s : q1) {
            for(int d = 0; d < L; d++) {
                vector<int> gen;
                for(int e : s) {
                    for(int to : adj[e][d]) if(!vis[to]) {
                        dis[to] = dis[e] * 10ll % mod + d;
                        dis[to] %= mod;

                        vis[to] = 1;
                        gen.push_back(to);
                    }
                }

                if(!gen.empty()) q2.push_back(gen);
            }
        }
        q1 = q2;
        q2.clear();
    }

    for(int i = 2; i <= n; i++) {
        cout << dis[i] << "\n";
    }

    return 0;
}
