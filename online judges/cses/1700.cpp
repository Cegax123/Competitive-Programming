#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int d[maxn];
int x[maxn];

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
long long random(long long l, long long r){
   return uniform_int_distribution<long long>(l,r)(rng);
}

void gen() {
    for(int i = 0; i < maxn; i++) {
        x[i] = random(2, mod-1);
    }
}

vector<int> adj[maxn];

void predfs(int v, int p = -1) {
    d[v] = 0;
    for(int to : adj[v]) if(to != p) {
        predfs(to, v);
        d[v] = max(d[v], d[to] + 1);
    }
}

int dfs(int v, int p = -1) {
    int h = 1;

    for(int to : adj[v]) if(to != p) {
        int hto = dfs(to, v);
        
        h = h * 1ll * ((x[d[v]] + hto) % mod) % mod;
    }

    return h;
}

void clean(int n) {
    for(int i = 0; i < n; i++) adj[i].clear();
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    gen();
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        
        int h[2];
        for(int tt = 0; tt < 2; tt++) {
            for(int i = 0; i < n-1; i++) {
                int u, v; cin >> u >> v; u--; v--;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            predfs(0);
            h[tt] = dfs(0);
            clean(n);
        }

        cout << (h[0] == h[1] ? "YES\n" : "NO\n");
    }

	
    return 0;
}


