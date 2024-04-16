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

const int maxn = 3005;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vi adj[n];

    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    set<int> banned[maxn][maxn];

    for(int i = 0; i < k; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--; c--;

        banned[a][b].insert(c);
    }

    int d[maxn][maxn];
    int par[maxn][maxn];
    bool vis[maxn][maxn];

    memset(vis, 0, sizeof(vis));

    d[0][0] = 0;
    queue<ii> q;
    q.push({0, 0});

    while(!q.empty()) {
        ii u = q.front(); q.pop();

        int x = u.first, y = u.second;

        for(int to : adj[y]) if(!banned[x][y].count(to)) {
            int nx = y, ny = to;
            if(vis[nx][ny]) continue;

            d[nx][ny] = d[x][y] + 1;
            par[nx][ny] = x;
            vis[nx][ny] = 1;
        }
    }

    int bef = -1, dis = 1e5;

    for(int i = 0; i < n-1; i++) {
        if(vis[i][n-1]) {
            if(d[i][n-1] < dis) {
                dis = d[i][n-1];
                bef = i;
            }
        }
    }

    if(bef == -1) {
        cout << -1 << "\n";
        return 0;
    }

    vi v;
    v.pb(n-1); v.pb(bef);

    int nxt = n-1;

    while(bef) {
        int tbef = bef;
        bef = par[bef][nxt];
        nxt = tbef;
        v.pb(bef);
    }

    reverse(all(v));

    cout << v.size()-1 << "\n";

    for(int x : v) cout << x << " ";
	
    return 0;
}


