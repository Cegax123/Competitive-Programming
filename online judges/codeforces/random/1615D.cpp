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

const int maxn = 2e5+5;

int n, m;
int f[maxn];
vector<vii> tree, adj;
vector<bool> vis;

void init() {
    tree.clear(); adj.clear();
    tree.resize(n); adj.resize(n);

    vis.clear(); vis.resize(n, 0);

    for(int i = 0; i < n; i++)
        f[i] = -1;
}

int get_parity(ll x) {
    int cnt = 0;
    for(int i = 0; i < 40; i++) {
        if((x >> i) & 1ll)
            cnt++;
    }

    return (cnt&1);
}

void dfs(int v, int p=-1) {
    for(auto e : adj[v]) {
        int to = e.first, w = e.second;
        if(to == p or f[to] != -1) continue;

        f[to] = f[v] ^ w;
        dfs(to, v);
    }
}

void fill(int v, int p=-1) {
    for(auto e : tree[v]) {
        int to = e.first, w = e.second;
        if(to == p) continue;

        fill(to, v);

        cout << v+1 << " " << to+1 << " ";
        if(w != -1) cout << w << "\n";
        else cout << (f[v] ^ f[to]) << "\n";
    }
}

bool check(int src) {
    queue<int> q;
    q.push(src);
    vis[src] = 1;

    while(!q.empty()) {
        int v = q.front(); q.pop();

        for(auto e : adj[v]) {
            int to = e.first, w = e.second;
            if(!vis[to]) {
                q.push(to);
                vis[to] = 1;
            }

            if((f[v] ^ f[to]) != w)
                return 0;
        }
    }

    return 1;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        init();

        for(int i = 0; i < n-1; i++) {
            int a, b, v; cin >> a >> b >> v;
            a--; b--;

            tree[a].pb({b, v});
            tree[b].pb({a, v});

            if(v != -1) {
                adj[a].pb({b, get_parity(v)});
                adj[b].pb({a, get_parity(v)});
            }
        }

        for(int i = 0; i < m; i++) {
            int a, b, v; cin >> a >> b >> v;
            a--; b--;

            adj[a].pb({b, v});
            adj[b].pb({a, v});
        }

        bool cmp = 1;
        
        f[0] = 0;
        dfs(0);

        if(!check(0)) 
            cmp = 0;

        for(int i = 0; i < n; i++) {
            if(f[i] == -1) {
                f[i] = 0;
                dfs(i);
                
                if(!check(i)) 
                    cmp = 0;
            }
        }

        if(!cmp) 
            cout << "NO\n";
        else {
            cout << "YES\n";
            fill(0);
        }
    }

	
    return 0;
}


