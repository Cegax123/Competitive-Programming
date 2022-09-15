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
//

const int maxn = 3e5+5;

vector<vi> adj;
vi d;
int n;
const int l = 21;
int timer;
vector<vector<int>> up;
int tin[maxn], tout[maxn];

void init() {
    adj.clear(); adj.resize(n);
    d.clear(); d.resize(n);
    up.clear(); up.resize(n, vi(l+1));

    timer = 0;
}

void dfs(int v, int p)
{
    if(v == 0) d[v] = 0;
    else d[v] = d[p]+1;

    tin[v] = ++timer;
    up[v][0] = p;

    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
    while(t--) {
        cin >> n;

        for(int i = 0; i < n; i++) {
            int u, v; cin >> u >> v;
        }
    }
	
	return 0;
}

