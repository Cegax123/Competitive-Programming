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
    vii adj[n+1];

    for(int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    ll d[n+1][2][2];
    const ll INF = (ll) 1e18;
    
    for(int i = 0; i <= n; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                d[i][j][k] = INF;

    struct State {
        int u, M, m;
    };

    auto cmp = [](pair<ll, State> a, pair<ll, State> b) {
        return a.first <= b.first;
    };

    set<pair<ll, State>, decltype(cmp)> s(cmp);
    s.insert({0, {1, 0, 0}});

    d[1][0][0] = 0;

    while(!s.empty()) {
        auto x = *s.begin(); s.erase(s.begin());

        ll dis_x = x.first;
        int u = x.second.u;
        int M = x.second.M;
        int m = x.second.m;

        if(d[u][M][m] != dis_x) continue;


        for(auto e : adj[u]) {
            int to = e.first, w = e.second;

            if(dis_x + w < d[to][M][m]) {
                d[to][M][m] = dis_x + w;
                s.insert({dis_x + w, {to, M, m}});
            }

            if(M == 0 and dis_x < d[to][1][m]) {
                d[to][1][m] = dis_x;
                s.insert({dis_x, {to, 1, m}});
            }

            if(m == 0 and dis_x + 2 * w < d[to][M][1]) {
                d[to][M][1] = dis_x + 2 * w;
                s.insert({dis_x + 2 * w, {to, M, 1}});
            }

            if(M == 0 and m == 0 and dis_x + w < d[to][1][1]) {
                d[to][1][1] = dis_x +  w;
                s.insert({dis_x + w, {to, 1, 1}});
            }
        }
    }

    for(int i = 2; i <= n; i++)
        cout << d[i][1][1] << " ";
	
    return 0;
}


