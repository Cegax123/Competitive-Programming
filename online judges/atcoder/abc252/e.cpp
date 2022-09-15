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

const int maxn = 2e5;
const ll INF = (ll) 1e18;

struct Edge {
    int from, to, c, id;
};

vector<Edge> adj[maxn+5];
vector<ll> d(maxn+5, INF);
vi ans;

void dijkstra(int s) {
    d[s] = 0;

    priority_queue<pair<ll, ii>, vector<pair<ll, ii>>, greater<pair<ll, ii>>> q;
    q.push({0, {s, 0}});
    while (!q.empty()) {
        int v = q.top().second.first;
        ll d_v = q.top().first;
        int id = q.top().second.second;
        q.pop();
        if (d_v != d[v])
            continue;

        ans.pb(id);

        for (auto edge : adj[v]) {
            int to = edge.to;
            ll len = edge.c;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                q.push({d[to], {to, edge.id}});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;

        adj[a].pb({a, b, c, i+1});
        adj[b].pb({b, a, c, i+1});
    }

    dijkstra(1);

    for(int i = 1; i < n; i++)
        cout << ans[i] << " ";

    cout << "\n";
   
    return 0;
}


