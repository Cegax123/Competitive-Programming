#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+5;
const int mod = 1e9 + 7;
const int k = 2;
int x[k][maxn];

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
long long random(long long l, long long r) {
    return uniform_int_distribution(l, r)(rng);
}

void gen() {
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < maxn; j++)
            x[i][j] = random(0, mod-1);
}

vector<int> adj[maxn];
int d[maxn];
int h[k][maxn];
long long H[maxn];

void dfs(int v, int p=-1) {
    d[v] = 0;
    for(int to : adj[v]) if(to != p) {
        dfs(to, v);
        d[v] = max(d[v], d[to]+1);
    }
}

void calc(int v, int p=-1) {
    for(int i = 0; i < k; i++)
        h[i][v] = 1;

    for(int to : adj[v]) if(to != p) {
        calc(to, v);

        for(int i = 0; i < k; i++)
            h[i][v] = h[i][v] * 1ll * ((x[i][d[v]] + h[i][to]) % mod) % mod;
    }

    H[v] = h[0][v] * 1ll * mod + h[1][v];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    gen();
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for(int i = 0; i < n-1; i++) {
            int u, v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i = 0; i < n; i++)
            adj[i].clear();

        dfs(0);
        calc(0);

        for(int i = 0; i < n; i++)
            cout << H[i] << "\n";
    }

	
    return 0;
}


