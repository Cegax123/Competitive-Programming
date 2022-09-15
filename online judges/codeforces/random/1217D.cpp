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

const int maxn = 5005;

int n, m; 
vi adj[maxn];
int color[maxn];

bool dfs(int v) {
    color[v] = 1;

    for(int to : adj[v]) {
        if(color[to] == 0) {
            if(dfs(to))
                return 1;
        }
        else if(color[to] == 1) {
            return 1;
        }
    }
    
    color[v] = 2;
    return 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    vii edges;

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;

        adj[u].pb(v);
        edges.pb({u, v});
    }

    bool exists_cycle = 0;
    for(int i = 0; i < n; i++) {
        if(color[i] == 0) {
            if(dfs(i)) exists_cycle = 1;
        }
    }

    if(exists_cycle) {
        cout << "2\n";

        for(int i = 0; i < m; i++) {
            if(edges[i].first < edges[i].second) cout << 1 << " ";
            else cout << 2 << " ";
        }
        cout << "\n";
    }
    else {
        cout << "1\n";
        for(int i = 0; i < m; i++)
            cout << 1 << " ";
        cout << "\n";
    }
	
    return 0;
}


