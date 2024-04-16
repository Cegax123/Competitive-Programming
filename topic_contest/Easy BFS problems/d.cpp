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



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k, d; cin >> n >> k >> d;
    vi col(n);

    queue<int> q;
    for(int i = 1; i <= k; i++) {
        int x; cin >> x; x--;
        q.push(x);
        col[x] = i;
    }

    vi adj[n];
    vii edges;
    for(int i = 1; i <= n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;

        adj[u].pb(v);
        adj[v].pb(u);

        edges.pb({u, v});
    }

    while(!q.empty()){
        int u = q.front(); q.pop();

        for(int to : adj[u]) if(col[to] == 0) {
            col[to] = col[u];
            q.push(to);
        }
    }

    int cnt = 0;
    for(int i = 0; i < n-1; i++) {
        if(col[edges[i].first] != col[edges[i].second]) {
            cnt++;
        }
    }

    cout << cnt << "\n";
    for(int i = 0; i < n-1; i++) {
        if(col[edges[i].first] != col[edges[i].second]) {
            cout << i+1 << " ";
        }
    }
	
    return 0;
}


