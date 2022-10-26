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


struct Edge {
    ll d;
    int v, pv, ed;
    ll w;
};


struct cmp {
    bool operator() (const Edge& a, const Edge& b) const {
        return a.d < b.d;
    }
};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vi g[n][m];

        for(int i = 0; i < m; i++) {
            int u, v, w; cin >> u >> v >> w;
            u--; v--;

            g[u][v].pb(w);

            if(g[u][v].size() > 2) {
                sort(all(g[u][v]));
                g[u][v].pop_back();
            }

            g[v][u] = g[u][v];
        }

        vii adj[n];
        vii sec[n];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!g[i][j].empty()) {
                    adj[i].pb({j, g[i][j][0]});
                }
                if(g[i][j].size() == 2) {
                    sec[i].pb({j, g[i][j][1]});
                }
            }
        }

        //for(int i = 0; i < n; i++) {
            //cout << i << ": ";
            //for(auto e : adj[i]) {
                //cout << e.first << ", " << e.second << " ";
            //}
            //cout << endl;
        //}

        const ll INF = (ll) 2e18;
        ll d[n][n][2];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                d[i][j][0] = d[i][j][1] = INF;

        set<Edge, cmp> pq;

        d[0][0][0] = 0;
        pq.insert({0, 0, 0, 0, INF});

        while(!pq.empty()) {
            auto x = *pq.begin(); pq.erase(pq.begin());
            
            ll d_v = x.d;
            ll curr_w = x.w;
            int v = x.v, pv = x.pv, ed = x.ed;

            if(d_v != d[pv][v][ed]) continue;
            
            for(auto e : sec[v]) {
                int to = e.first; ll w = e.second;
                if(to == pv and ed == 1) continue;

                if(d_v + w < d[v][to][1]) {
                    d[v][to][1] = d_v+w;

                    Edge a;
                    a.d = d[v][to][1];
                    a.v = to;
                    a.pv = v;
                    a.ed = 1;
                    pq.insert(a);
                }
            }

            for(auto e : adj[v]) {
                int to = e.first; ll w = e.second;
                if(to == pv and ed == 0) continue;

                if(d_v + curr_w < d[pv][to][0]) {
                    d[pv][to][0] = d_v + curr_w;
                    pq.insert({d[pv][to][0], to, pv, 0, curr_w});
                }

                if(d_v + w < d[v][to][0]) {
                    d[v][to][0] = d_v + w;
                    pq.insert({d[v][to][0], to, v, 0, w});
                }
            }
        }

        //for(int i = 0; i < n; i++) {
            //for(int j = 0; j < n; j++) {
                //if(i == j) continue;

                //cout << i << " " << j << " " << d[i][j][0] << " " << d[i][j][1] << endl;
            //}
        //}

        ll ans = INF;
        for(int i = 0; i < n-1; i++) {
            ans = min(ans, d[i][n-1][0]);
            ans = min(ans, d[i][n-1][1]);
        }

        cout << ans << "\n";
    }

	
    return 0;
}


