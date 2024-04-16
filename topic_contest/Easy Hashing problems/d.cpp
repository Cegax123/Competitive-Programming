#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
const int mod = 1e9 + 7;
int x[2][maxn];

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
long long random(long long l, long long r){
    return uniform_int_distribution<long long>(l,r)(rng);
}

void gen() {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < maxn; j++) {
            x[i][j] = random(0, mod-1);
        }
    }
}

vector<int> adj[maxn];
vector<vector<int>> h(maxn);
int d[maxn];
int f[maxn], s[maxn];

void dfs1(int v, int p=-1) {
    for(int i = 0; i < 3; i++)
        h[v].emplace_back(0);

    for(int to : adj[v]) if(to != p) {
        dfs1(to, v);

        h[v][0] = h[to][2] + 1;
        sort(h[v].begin(), h[v].end());
    }

    d[v] = h[v][2];
}

void dfs2(int v, int p=-1) {
    if(p == -1) f[v] = h[v][2], s[v] = h[v][1];

    for(int to : adj[v]) if(to != p) {
        vector<int> best(3);
        best[0] = h[to][2];
        best[1] = h[to][1];

        if(d[to] + 1 == f[v]) best[2] = s[v]+1;
        else best[2] = f[v]+1;

        sort(best.begin(), best.end());

        f[to] = best[2];
        s[to] = best[1];

        dfs2(to, v);
    }
}

int ex(int a, int b, int c) {
    int ans = 1;
    while(b) {
        if(b&1) ans = ans * 1ll * a % c;
        a = a * 1ll * a % c;
        b >>= 1;
    }

    return ans;
}

int pf[2][maxn], ps[2][maxn], pd[2][maxn];
long long p[maxn];

void prehash(int v, int p=-1) {
    for(int i = 0; i < 2; i++) 
        pf[i][v] = ps[i][v] = pd[i][v] = 1;

    for(int to : adj[v]) if(to != p) {
        prehash(to, v);

        for(int i = 0; i < 2; i++) {
            pf[i][v] = pf[i][v] * 1ll * ((x[i][f[v]] + pd[i][to]) % mod) % mod;
            ps[i][v] = ps[i][v] * 1ll * ((x[i][s[v]] + pd[i][to]) % mod) % mod;
            pd[i][v] = pd[i][v] * 1ll * ((x[i][d[v]] + pd[i][to]) % mod) % mod;
        }
    }
}

set<long long> ht;

void get_hash(int v, int p=-1) {
    ht.insert(pf[0][v] * 1ll * mod + pf[1][v]);
    for(int to : adj[v]) if(to != p) {

        for(int i = 0; i < 2; i++) {
            int T;
            if(d[to] + 1 == f[v]) T = ps[i][v] * 1ll * ex((x[i][s[v]] + pd[i][to]) % mod, mod-2, mod) % mod;
            else T = pf[i][v] * 1ll * ex((x[i][f[v]] + pd[i][to]) % mod, mod-2, mod) % mod;

            pf[i][to] = pf[i][to] * 1ll * ((x[i][f[to]] + T) % mod) % mod;
            ps[i][to] = ps[i][to] * 1ll * ((x[i][s[to]] + T) % mod) % mod;
        }

        get_hash(to, v);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    gen();

    int n; cin >> n;
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(0);
    dfs2(0);

    prehash(0);
    get_hash(0);

    cout << ht.size() << "\n";

    //for(int i = 0; i < n; i++) {
        //cout << i+1 << ": " << f[i] << " " << s[i] << endl;
    //}
	
    return 0;
}


