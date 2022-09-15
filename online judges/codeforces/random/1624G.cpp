#include <bits/stdc++.h>
#include <ios>
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


struct Edge {
    int to, w, id;  
};

const int maxn = 2e5+5;

vector<Edge> adj[maxn];
bool deleted[maxn];
ll w[maxn];
bool vis[maxn];
int n, m;

void dfs(int v = 0) {
    vis[v] = 1;

    for(Edge e : adj[v]) {
        int to = e.to, id = e.id;
        if(deleted[id]) continue;

        if(!vis[to]) 
            dfs(to);
    }
}

bool check() {
    for(int i = 0; i < n; i++)
        vis[i] = 0;
    dfs();

    for(int i = 0; i < n; i++)
        if(vis[i] == 0) return 0;

    return 1;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n >> m;

        for(int i = 0; i < n; i++) 
            adj[i].clear();
        

        for(int i = 0; i < m; i++) {
            int a, b, x; cin >> a >> b >> x;
            a--; b--; 
            
            w[i] = x;
            deleted[i] = 0;

            adj[a].pb({b, x, i});
            adj[b].pb({a, x, i});
        }

        ll ans = 0;

        for(int i = 40; i >= 0; i--) {
            vi tmp;

            for(int j = 0; j < m; j++) {
                if(deleted[j]) continue;
                if((w[j] >> i)&1) {
                    deleted[j] = 1;
                    tmp.pb(j);
                }
            }

            if(!check()) {
                for(int id : tmp) {
                    deleted[id] = 0;
                }
                    
                ans |= (1ll << i);
            }
            
        }

        cout << ans << "\n";
    }
	
	return 0;
}

