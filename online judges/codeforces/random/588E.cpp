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
const int LOGN = 20;

vi adj[maxn];
vi A[maxn];
int T = 0;
int st[maxn], fin[maxn];
int up[maxn][LOGN];
vi pep[maxn][LOGN];
int h[maxn];

vi combine(const vi& a, const vi& b) {
	vi c;

	int inda = 0, indb = 0;
	int ka = a.size(), kb = b.size();
	while((int) c.size() < 10) {
		if(inda == ka and indb == kb) break;
		if(inda == ka) {
			c.pb(b[indb]);
			indb++;
		}
		else if(indb == kb) {
			c.pb(a[inda]);
			inda++;
		}
		else {
			if(a[inda] < b[indb]) {
				c.pb(a[inda]);
				inda++;
			}
			else if(b[indb] < a[inda]) {
				c.pb(b[indb]);
				indb++;
			}
			else {
				c.pb(a[inda]);
				inda++; indb++;
			}
		}
	}

	return c;
}

void dfs(int v, int p) {
	st[v] = T++;
	
	if(v == 1) h[v] = 0;
	else h[v] = h[p]+1;

	up[v][0] = p;
	for(int i = 1; i < LOGN; i++)
		up[v][i] = up[up[v][i-1]][i-1];

	pep[v][0] = combine(A[v], A[p]);

	for(int i = 1; i < LOGN; i++)
		pep[v][i] = combine(pep[v][i-1], pep[up[v][i-1]][i-1]);

	for(auto to : adj[v]) {
		if(to == p) continue;
		dfs(to, v);
	}

	fin[v] = T++;
}

bool is_ancestor(int v, int u) {
	return st[v] <= st[u] and fin[u] <= fin[v];
}

int lca(int v, int u) {
	if(is_ancestor(v, u)) return v;
	if(is_ancestor(u, v)) return u;

	for(int i = LOGN-1; i >= 0; i--) {
		if(!is_ancestor(up[v][i], u)) {
			v = up[v][i];
		}
	}

	return up[v][0];
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, q; cin >> n >> m >> q;

    for(int i = 0; i < n-1; i++) {
    	int u, v; cin >> u >> v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }

	for(int i = 1; i <= m; i++) {
		int x; cin >> x;
		A[x].pb(i);
	}

	for(int i = 1; i <= n; i++) {
		sort(all(A[i]));

		while((int) A[i].size() > 10) {
			A[i].pop_back();
		}
	}

	dfs(1, 1);

	while(q--) {
		int u, v, a; cin >> u >> v >> a;
		int p = lca(u, v);

		int k1 = h[u]-h[p], k2 = h[v]-h[p];

		vi s = combine(A[u], A[v]);

		for(int i = 0; i < LOGN; i++) {
			if((k1 >> i)&1) {
				s = combine(s, pep[u][i]);
				u = up[u][i];
			}
			if((k2 >> i)&1) {
				s = combine(s, pep[v][i]);
				v = up[v][i];
			}
		}

		int k = min((int) s.size(), a);

		cout << k << " ";
		for(int i = 0; i < k; i++)
			cout << s[i] << " ";
		
		cout << "\n";
	}

	
    return 0;
}
