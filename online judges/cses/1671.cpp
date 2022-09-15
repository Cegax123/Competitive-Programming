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

const int maxn = 1e5+5;
const ll INF = (ll) 1e18;

vii adj[maxn];
vector<ll> d(maxn, INF);

void dijkstra(int src) {
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;

    d[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        auto a = pq.top(); pq.pop();
        ll dv = a.first, v = a.second;

        if(dv != d[v])
            continue;

        for(auto e : adj[v]) {
            int to = e.first, w = e.second;

            if(dv + w < d[to]) {
                d[to] = dv + w;
                pq.push({d[to], to});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, m; cin >> n >> m;
	
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        int c; cin >> c;
        a--; b--;

        adj[a].pb({b, c});
    }

    dijkstra(0);

    for(int i = 0; i < n; i++) {
        cout << d[i] << " ";
    }
	
	return 0;
}

