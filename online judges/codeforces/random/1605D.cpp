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
vi a, b;

void dfs(int v, int p, int h) {
	if(h==0) a.pb(v);
	else b.pb(v);
	
	for(auto to : adj[v]) {
		if(to == p) continue;
		dfs(to, v, 1-h);
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		
		a.clear(); b.clear();
	
		for(int i = 1; i <= n; i++)
			adj[i].clear();
			
		for(int i = 0; i < n-1; i++) {
			int u, v; cin >> u >> v;
			adj[u].pb(v),
			adj[v].pb(u);
		}
		
		dfs(1,1,0);
		
		int inda = 0, indb = 0;
		int lefta = a.size(), leftb = b.size();
		
		int ans[n+1];
		int c[n+1];
		
		c[1] = 0;
		
		for(int i = 2; i <= n; i++) 
			c[i] = c[i>>1]+1;
		
		int ind = n;
		while(ind >= 1) {
			int to = ind;
			int cnt = 0;
			
			while(to >= 1 and c[to] == c[ind]) {
				to--;
				cnt++;
			}
			to++;
			
			if(lefta >= leftb) {
				for(int i = to; i <= ind; i++) {
					ans[a[inda++]] = i;
					lefta--;
				}
			}
			else {
				for(int i = to; i <= ind; i++) {
					ans[b[indb++]] = i;
					leftb--;
				}
			}
			
			ind = to-1;
		}
		
		for(int i = 1; i <= n; i++)
			cout << ans[i] << " ";
		cout << "\n";
	}
	
	return 0;
}
