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

const int maxn = 2e5+5;

int n;
vi adj[maxn];
int sz[maxn];
int ans;

void dfs(int v, int p = -1) {
    sz[v] = 1;

    for(int to : adj[v]) {
        if(to == p) continue;

        dfs(to, v);
        sz[v] += sz[to];
    }

    bool cmp = 1;
    for(int to : adj[v]) {
        if(to == p) continue;

        if(sz[to] > n/2) cmp = 0;
    }

    if(n-sz[v] > n/2) cmp = 0;

    if(cmp) ans = v;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;

    for(int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
	
    dfs(0);

    cout << ans+1 << "\n";
	
	return 0;
}

