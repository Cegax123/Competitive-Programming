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
vi adj[maxn];

int h[maxn];
int mh[maxn];
vector<vi> c[maxn];

void dfs(int v, int p=0) {
    if(p == 0) h[v] = 0;
    else h[v] = h[p]+1;

    mh[v] = h[v];

    for(int to : adj[v]) {
        dfs(to, v);
        
        mh[v] = max(mh[v], mh[to]);
        c[v].pb(mh[to]);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q; cin >> n >> q;

    for(int i = 0; i < n-1; i ++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }


	
    return 0;
}


