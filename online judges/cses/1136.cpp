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
const int LOGN = 20;

vi adj[maxn];
int timer = 0; 
int tin[maxn], tout[maxn];
int up[maxn][LOGN+1];
int val[maxn], deg[maxn];

// dfs(root, root)
void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;

    for(int i = 1; i <= LOGN; i++) 
        up[v][i] = up[up[v][i-1]][i-1];

    for(int to : adj[v]) {
        if(to == p) continue;

        deg[v]++;
        dfs(to, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = LOGN; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
    int n, q; cin >> n >> q;

    for(int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(0, 0);
	
    while(q--) {
        int a, b; cin >> a >> b;
        a--; b--;

        int k = lca(a, b);

        if(a == b) {
            if(a) val[up[a][0]]--;
            val[a]++;
        }
        else if(a == k) {
            if(a) val[up[a][0]]--;
            val[b]++;
        }
        else if(b == k) {
            if(b) val[up[b][0]]--;
            val[a]++;
        }
        else {
            if(k) val[up[k][0]]--;
            val[k]--;

            val[a]++;
            val[b]++;
        }
    }

    queue<int> Q;
    
    for(int i = 0; i < n; i++)
        if(deg[i] == 0) Q.push(i);

    while(!Q.empty()) {
        int v = Q.front(); Q.pop();
        
        if(v == 0) continue;

        int par = up[v][0];
        val[par] += val[v];
        deg[par]--;

        if(deg[par] == 0) 
            Q.push(par);
    }

    for(int i = 0; i < n; i++) {
        cout << val[i] << " ";
    }
	
	return 0;
}

