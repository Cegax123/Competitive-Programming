#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//cout << setprecision(12) << fixed;

const int maxn = 1e5 + 5;
vector<vector<int>> adj[2];

vector<int> Centroid(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> centroid;
    vector<int> sz(n);

    function<void (int, int)> dfs = [&](int u, int prev) {
        sz[u] = 1;
        bool is_centroid = true;

        for(auto v : adj[u]) if(v != prev) {
            dfs(v, u);
            sz[u] += sz[v];
            if(sz[v] > n/2) is_centroid = false;
        }

        if(n-sz[u] > n/2) is_centroid = false;
        if(is_centroid) centroid.emplace_back(u);
    };
    dfs(0, -1);
    return centroid;
}

const int mod = 1e9 + 7;
int x[maxn];
int d[maxn];

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
long long random(long long l, long long r){
   return uniform_int_distribution<long long>(l,r)(rng);
}

void gen() {
    for(int i = 0; i < maxn; i++) {
        x[i] = random(2, mod-1);
    }
}

void predfs(const vector<vector<int>>& adj, int v, int p=-1) {
    d[v] = 0;
    for(int to : adj[v]) if(to != p) {
        predfs(adj, to, v);
        d[v] = max(d[v], d[to] + 1);
    }
}

int get_hash(const vector<vector<int>>& adj, int v, int p=-1) {
    int h = 1;

    for(int to : adj[v]) if(to != p) {
        int hto = get_hash(adj, to, v);
        h = h * 1ll * ((x[d[v]] + hto) % mod) % mod;
    }

    return h;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    gen();

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> h[2];
        for(int c = 0; c < 2; c++) {
            adj[c].clear();
            adj[c].resize(n);

            vector<int> centroids;

            for(int i = 0; i < n-1; i++) {
                int u, v; cin >> u >> v;
                u--; v--;

                adj[c][u].emplace_back(v);
                adj[c][v].emplace_back(u);
            }

            centroids = Centroid(adj[c]);

            for(int cc : centroids) {
                predfs(adj[c], cc);
                h[c].emplace_back(get_hash(adj[c], cc));
            }
        }

        bool cmp = false;
        for(int x : h[0]) for(int y : h[1]) if(x == y) cmp = true;

        cout << (cmp ? "YES\n" : "NO\n");

    }


    return 0;
}


