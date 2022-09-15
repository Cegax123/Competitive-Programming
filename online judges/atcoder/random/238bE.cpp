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

bool vis[maxn];
vi adj[maxn];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, q; cin >> n >> q;

    while(q--) {
        int u, v; cin >> u >> v;
        u--;
        
        adj[u].pb(v);
        adj[v].pb(u);
    }

    queue<int> Q;
    Q.push(0);

    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        vis[u] = 1;

        for(int to : adj[u]) {
            if(vis[to]) continue;
            Q.push(to);
        }
    }

    cout << (vis[n] ? "Yes\n" : "No\n");
	
	return 0;
}

