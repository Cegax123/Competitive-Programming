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
    int n; cin >> n;
    vi adj[n+1];

    for(int i = 1; i <= n; i++) {
        int u; cin >> u;
        int k; cin >> k;

        for(int j = 0; j < k; j++) {
            int v; cin >> v;
            adj[u].pb(v);
        }
    }

    vi d(n+1, 1e9);

    queue<int> q;
    q.push(1);

    d[1] = 0;

    while(!q.empty()) {
        int v = q.front(); q.pop();

        for(int to : adj[v]) {
            if(d[to] == 1e9) {
                d[to] = d[v] + 1;
                q.push(to);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << i << " " << (d[i] == 1e9 ? -1 : d[i]) << "\n";
    }
	
    return 0;
}


