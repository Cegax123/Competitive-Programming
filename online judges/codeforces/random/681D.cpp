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

int p[maxn];
vi adj[maxn];
int a[maxn];

vi ans;
bool cmp = 1;

void dfs(int v) {
    if(a[v] != v) {
        if(p[v] == 0) cmp = 0;
        else if(a[p[v]] != a[v]) cmp = 0;
    }

    for(int to : adj[v]) {
        dfs(to);
    }

    if(a[v] == v) 
        ans.pb(v);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);

        p[v] = u;
    }

    for(int i = 1; i <= n; i++)
        cin >> a[i];
	
    for(int i = 1; i <= n; i++) {
        if(p[i] == 0) {
            dfs(i);
        }
    }

    if(cmp == 0) cout << "-1\n";
    else {
        cout << ans.size() << "\n";
        for(int x : ans)
            cout << x << "\n";
    }
	
	return 0;
}

