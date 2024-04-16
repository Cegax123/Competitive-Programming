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

const int maxn = 1e5 + 5;
const int maxst = 130;

int d[maxn][maxst];
vii adj[maxn];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(d, -1, sizeof(d));

    int n, m, k; cin >> n >> m >> k;
    queue<ii> q;

    for(int i = 0; i < k; i++) {
        int x; cin >> x;
        x--;

        q.push({x, 0});
        d[x][0] = 0;
    }

    for(int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        a--; b--;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }

    while(!q.empty()) {
        int u = q.front().first, st = q.front().second; q.pop();

        for(auto& e : adj[u]) {
            int to = e.first, w = e.second;
            int nst = (st ^ w);

            if(d[to][nst] != -1) continue;

            d[to][nst] = d[u][st] + 1;
            q.push({to, nst});
        }
    }

    int p; cin >> p;
    while(p--) {
        int u; cin >> u;
        u--;

        bool found = false;
        double ans = 0.0;

        for(int i = 0; i < maxst; i++) {
            if(d[u][i] != -1) {
                found = true;
                ans = max(ans, i * 1.0 / d[u][i]);
            }
        }

        if(!found) cout << "unreachable\n";
        else cout << setprecision(6) << fixed << ans << "\n";
    }
	
    return 0;
}


