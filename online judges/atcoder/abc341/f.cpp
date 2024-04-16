#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5005;

vector<int> radj[maxn];
vector<int> adj[maxn];
ll val[maxn];

int main() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> edges;
    int w[n], a[n];

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        edges.push_back({u, v});
    }

    for(int i = 0; i < n; i++) cin >> w[i];
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> out(n, 0);

    for(auto e : edges) {
        if(w[e.first] < w[e.second]) {
            radj[e.first].push_back(e.second);
            adj[e.second].push_back(e.first);
            out[e.second]++;
        }
        else if(w[e.first] > w[e.second]) {
            radj[e.second].push_back(e.first);
            adj[e.first].push_back(e.second);
            out[e.first]++;
        }
    }

    queue<int> q;

    for(int i = 0; i < n; i++) if(out[i] == 0) q.push(i);

    const int maxw = 5005;

    while(!q.empty()) {
        int v = q.front(); q.pop();
        val[v] = 1;

        vector<ll> kn(maxw, -1);
        kn[0] = 0;

        for(int to : adj[v]) {
            for(int i = maxw-1; i >= 0; i--) {
                if(i + w[to] < maxw and kn[i] >= 0) kn[i + w[to]] = max(kn[i + w[to]], kn[i] + val[to]);
            }
        }

        ll ans = 0;
        for(int i = 0; i < w[v]; i++) ans = max(ans, kn[i]);
        val[v] += ans;

        for(int to : radj[v]) {
            out[to]--;
            if(out[to] == 0) q.push(to);
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) ans += a[i] * 1ll * val[i];

    cout << ans << "\n";

    return 0;
}
