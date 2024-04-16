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
vector<vi> adj;
int a[maxn];
int parent[maxn], sz[maxn];
set<ii> edges[maxn];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

void union_sets(int a, int b, bool union_edges=0) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            u--; v--;
            if(a[u]+1 >= a[v]) adj[u].pb(v);
            else edges[u].insert({a[v]-a[u], v});

            if(a[v]+1 >= a[u]) adj[v].pb(u);
            else edges[v].insert({a[u]-a[v], u});
        }

        queue<int> q;

        vector<bool> vis(n, 0);
        for(int i = 0; i < n; i++) {
            if(a[i] == 0) {
                q.push(i);
                vis[i] = 1;
            }
        }
        
        
        if(q.empty()) {
            cout << "NO\n";
            continue;
        }

        
    }

	
    return 0;
}


