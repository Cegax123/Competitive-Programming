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
    int v[n];

    for(int i = 0; i < n; i++)
        cin >> v[i];

    vi adj[n];
    ll sum[n];

    memset(sum, 0, sizeof(sum));

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;

        adj[a].pb(b);
        adj[b].pb(a);

        sum[a] += v[b];
        sum[b] += v[a];
    }

    set<pair<ll, int> > s;

    for(int i = 0; i < n; i++)
        s.insert({sum[i], i});

    ll ans = 0;

    bool vis[n];
    memset(vis, 0, sizeof(vis));

    while(!s.empty()) {
        auto x = *s.begin(); s.erase(x);

        vis[x.second] = 1;

        ans = max(ans, x.first);

        for(int to : adj[x.second]) {
            if(vis[to]) continue;

            s.erase({sum[to], to});

            sum[to] -= v[x.second];

            s.insert({sum[to], to});
        }
    }

    cout << ans << "\n";
	
    return 0;
}


