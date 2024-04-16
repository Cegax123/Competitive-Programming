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

vector<vi> adj;
int h[maxn];
int sx[maxn], cx[maxn];

void dfs(int v, int par) {
    h[v] = (v == 0 ? 0 : h[par] + 1);

    if(h[v]&1) sx[v] = 1;
    else if(v) sx[v] = -1;

    cx[v] = sx[v];

    for(int to : adj[v]) if(par != to) {
        dfs(to, v);

        cx[v] -= sx[to];
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;

        adj.clear(); adj.resize(n);

        for(int i = 0; i < n-1; i++) {
            int u, v; cin >> u >> v;
            u--; v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        dfs(0, -1);

        for(int i = 0; i < n; i++)
            cout << cx[i] << " ";

        cout << "\n";
    }
	
    return 0;
}


