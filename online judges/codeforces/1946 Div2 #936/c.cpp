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
vi adj[maxn];
int sz[maxn];

void predfs(int v, int p=-1) {
    sz[v] = 1;
    for(int to : adj[v]) if(to != p) {
        predfs(to, v);
        sz[v] += sz[to];
    }
}

int n, k;
int cnt;
bool cmp = 0;

int dfs(int v, int x, int p=-1) {
    int eras = 0;
    for(int to : adj[v]) if(to != p) {
        eras += dfs(to, x, v);
    }

    if(v == 0) return sz[v] - eras;

    if(sz[v] - eras >= x) {
        if(cnt < k) {
            cnt++;
            return sz[v];
        }
        else return eras;
    }

    return eras;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 0; i < n; i++) adj[i].clear();
        for(int i = 0; i < n-1; i++) {
            int u, v; cin >> u >> v;
            u--; v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        predfs(0);
        int l = 1, r = n;

        while(l < r) {
            int m = (l+r+1) >> 1;
            cnt = 0;
            int lft = dfs(0, m);

            //cout << m << " " << cnt << " " << lft << endl;

            if(cnt >= k and lft >= m) l = m;
            else r = m-1;
        }

        cout << l << "\n";
    }

	
    return 0;
}


