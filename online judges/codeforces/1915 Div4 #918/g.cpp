#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 1005;
vector<pair<int, int>> adj[maxn];
int s[maxn];
ll dp[maxn][maxn];
const ll INF = (ll) 1e18;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;

        for(int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            int w; cin >> w;
            u--; v--;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        for(int i = 0; i < n; i++) cin >> s[i];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < maxn; j++)
                dp[i][j] = INF;
        }

        dp[0][s[0]] = 0;

        set<pair<ll, pair<int, int>>> q;
        q.insert({0, {0, s[0]}});

        while(!q.empty()) {
            auto e = *q.begin(); q.erase(e);
            ll d_u = e.first;
            int u = e.second.first, s_u = e.second.second;

            if(dp[u][s_u] != d_u) continue;

            for(auto [to, w] : adj[u]) {
                int nsto = min(s[to], s_u);
                ll d_to = dp[u][s_u] + s_u * 1ll * w;

                if(dp[to][nsto] > d_to) {
                    dp[to][nsto] = d_to;
                    d_to = dp[to][nsto];
                    q.insert({d_to, {to, nsto}});
                }
            }
        }

        ll ans = INF;
        for(int i = 0; i < maxn; i++)
            ans = min(ans, dp[n-1][i]);

        cout << ans << "\n";

        for(int i = 0; i < n; i++)
            adj[i].clear();
    }
    

    return 0;
}
