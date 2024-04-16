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
int a[maxn];
int h[maxn];
int pos[maxn];
int par[maxn];
int cnt[maxn];
vi adj[maxn];
const int B = 320;
ll dp[maxn][B];

void dfs(int v, int p) {
    if(v == 0) h[v] = 0;
    else h[v] = h[p] + 1;

    pos[v] = cnt[h[v]]++;

    for(int to : adj[v]) if(to != p) {
        dfs(to, v);
    }
}

ll find(int x, int y) {
    if(x == 0) return a[0] * 1ll * a[0];
    if(x > y) swap(x, y);

    if(cnt[h[x]] <= B and dp[x][pos[y]]) return dp[x][pos[y]];

    ll ans = a[x] * 1ll * a[y] + find(par[x], par[y]);

    if(cnt[h[x]] <= B) dp[x][pos[y]] = ans;

    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i < n; i++) {
        cin >> par[i];
        par[i]--;

        adj[i].pb(par[i]);
        adj[par[i]].pb(i);
    }

    dfs(0, -1);


    for(int i = 0; i < q; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        cout << find(x, y) << "\n";
    }
	
    return 0;
}


