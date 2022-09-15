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

const int maxn = 1e5+5;

vector<vii> adj;
int ans[maxn];

void dfs(int v, int p, int val=2) {
    for(auto edge : adj[v]) {
        int to = edge.first, id = edge.second;
        if(to == p) continue;
        ans[id] = val;
        dfs(to, v, 5-val);
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        
        adj.clear(); 
        adj.resize(n);

        int d[n];
        memset(d, 0, sizeof(d));
        
        for(int i = 0; i < n-1; i++) {
            int u, v; cin >> u >> v;
            u--; v--;

            adj[u].pb({v, i});
            adj[v].pb({u, i});

            d[u]++;
            d[v]++;
        }

        bool comp = 1;
        for(int i = 0; i < n; i++) {
            if(d[i] >= 3) 
                comp = 0;
        }

        if(comp == 0) {
            cout << "-1\n";
            continue;
        }

        int src;

        for(int i = 0; i < n; i++)
            if(d[i] == 1) src = i;

        dfs(src, src);

        for(int i = 0; i < n-1; i++)
            cout << ans[i] << " ";

        cout << "\n";
    }
	
	
	return 0;
}

