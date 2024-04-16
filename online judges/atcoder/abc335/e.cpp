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
vector<pair<int, int>> adj[maxn];
int n;

int parent[maxn];
int sz[maxn];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
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

vector<int> in(maxn, 0);
vector<bool> vis(maxn, 0);

void dfs(int v) {
    for(auto [to, w] : adj[v]) if(!vis[to]) {
        in[to]++;
        vis[to] = 1;
        dfs(to);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int m; cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;

        if(a[u] <= a[v]) adj[u].push_back({a[v], a[u] != a[v]});
        if(a[v] <= a[u]) adj[v].push_back({a[u], a[v] != a[u]});
    }

    vis[0] = 1;
    dfs(0);

    vector<int> d(n, 0);

    queue<int> q;
    q.push(0);

    d[0] = 1;

    vis.clear();
    vis.resize(n, 0);
    vis[0] = 1;

    while(!q.empty()) {
        int u = q.front(); q.pop();

        for(auto [to, w] : adj[u]) if(!vis[to]) {
            d[to] = max(d[to], d[u] + w);
            in[to]--;
            if(in[to] == 0) {
                q.push(to);
                vis[to] = 1;
            }
        }
    }

    cout << d[n-1] << "\n";
	
    return 0;
}


