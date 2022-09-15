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
    int n, m; cin >> n >> m;
    vi adj[n];

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    const int INF = 1e9;

    int ans[1 << n][n];

    for(int i = 0; i < (1 << n); i++)
        for(int j = 0; j < n; j++)
            ans[i][j] = INF;

    queue<ii> q;

    for(int i = 0; i < n; i++) {
        q.push({1 << i, i});
        ans[1 << i][i] = 1;
    }

    while(!q.empty()) {
        int mask = q.front().first, u = q.front().second; q.pop();

        for(int to : adj[u]) {
            int next_mask = mask ^ (1 << to);
            if(ans[next_mask][to] < INF) continue;

            ans[next_mask][to] = ans[mask][u] + 1;
            q.push({next_mask, to});
        }
    }

    int res = 0;

    for(int i = 1; i < (1 << n); i++) {
        int curr = INF;
        for(int j = 0; j < n; j++) {
            curr = min(curr, ans[i][j]);
        }
        res += curr;
    }

    cout << res << "\n";
	
    return 0;
}


