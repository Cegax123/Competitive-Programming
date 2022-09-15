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

const int maxn = 2e5 + 5;
int parent[maxn], sz[maxn];

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

vi adj[maxn];
int val[maxn];
bool vis[maxn];
int p[maxn];
bool in_path[maxn];

int a = -1, b = -1;

void dfs(int v, int col) {
    vis[v] = 1;
    val[v] = col;

    for(int to : adj[v]) {
        if(in_path[to] or vis[to]) continue;
        dfs(to, col);
    }
}

void dfs2(int v = a, int par = -1) {
    if(par != -1) p[v] = par;

    if(v == b) in_path[v] = 1;

    for(int to : adj[v]) {
        if(to == par) continue;
        dfs2(to, v);

        if(in_path[to]) in_path[v] = 1;
    }
}



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;

    for(int i = 0; i < n; i++) 
        make_set(i);

    for(int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;
        u--; v--;

        if(find_set(u) == find_set(v) and a == -1) {
            a = u; 
            b = v;
        }
        else {
            adj[u].pb(v);
            adj[v].pb(u);
        }

        union_sets(u, v);
    }

    dfs2();

    int ind = 0;
    for(int i = 0; i < n; i++) {
        if(in_path[i]) dfs(i, ind++);
    }
    
    int q; cin >> q;
    while(q--) {
        int x, y; cin >> x >> y;
        x--; y--;

        if(val[x] != val[y]) cout << "No\n";
        else cout << "Yes\n";
    }
	
    return 0;
}


