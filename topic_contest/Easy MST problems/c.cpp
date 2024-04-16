#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge {
    int to, l, c;
};

const int maxn = 1e4 + 5;
vector<Edge> adj[maxn];

typedef pair<long long, int> ii;
typedef pair<ii, int> pii;

const ll INF = (ll) 1e18;

bool used[maxn];
ii dis[maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b, l, c; cin >> a >> b >> l >> c;
        a--; b--;

        adj[a].push_back({b, l, c});
        adj[b].push_back({a, l, c});
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for(int i = 0; i < n; i++) dis[i] = {INF, 1e9};

    dis[0] = {0, 0};
    pq.push({dis[0], 0});

    ll ans = 0;
    
    while(!pq.empty()) {
        auto el = pq.top(); pq.pop();
        int v = el.second;

        if(used[v]) continue;

        used[v] = 1;

        ii d_v = el.first;
        ans += d_v.second;

        for(auto[to, l, c] : adj[v]) if(!used[to]) {
            ii ndto = {dis[v].first + l, c};
        
            if(ndto < dis[to]) {
                dis[to] = ndto;
                pq.push({dis[to], to});
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
