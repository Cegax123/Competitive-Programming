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

const int maxn = 1e6+5;

int n, q;
vi a, cnt;
vi p, pinv, lb;
vector<vi> adj;

vi ans;

struct Query {
	int l, k, id, ans;
};

vector<vector<Query>> queries;

void init() {
	a.clear();
	a.resize(n+1);

	cnt.clear();
	cnt.resize(n+1, 0);

	adj.clear();
	adj.resize(n+1);

	p.clear();
	for(int i = 0; i <= n; i++)
		p.pb(i);

	pinv.clear();
	for(int i = 0; i <= n; i++)
		pinv.pb(i);

	lb.clear();
	lb.resize(n+1, n+1);

	lb[0] = 1;

	queries.clear();
	queries.resize(n+1);

	ans.clear();
	ans.resize(q);
}

void add(int x) {
	int i = pinv[x];
	int j = lb[cnt[x]+1]-1;

	int y = p[j];

	swap(p[i], p[j]);
	swap(pinv[x], pinv[y]);

	lb[cnt[x]+1]--;
	cnt[x]++;
}

void del(int x) {
	int i = pinv[x];
	int j = lb[cnt[x]];

	int y = p[j];

	swap(p[i], p[j]);
	swap(pinv[x], pinv[y]);

	lb[cnt[x]]++;
	cnt[x]--;
}

void dfs(int v, int par = -1) {
	add(a[v]);

	for(auto q : queries[v]) {
		int i = lb[q.l];
		if(i + q.k - 1 > n) ans[q.id] = -1;
		else ans[q.id] = ans[q.id] = p[i+q.k-1];
	}

	for(int to : adj[v]) {
		if(to == par) continue;
		dfs(to, v);
	}

	del(a[v]);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while(t--) {
		cin >> n >> q;
		
		init();


		for(int i = 1; i <= n; i++) 
			cin >> a[i];

		for(int i = 2; i <= n; i++) {
			int x; cin >> x;

			adj[x].pb(i);
			adj[i].pb(x);
		}

		for(int i = 0; i < q; i++) {
			int v, l, k; cin >> v >> l >> k;
			queries[v].pb({l, k, i});
		}

		dfs(1);

		for(int i = 0; i < q; i++) 
			cout << ans[i] << " ";
		cout << "\n";
	}
	
	return 0;
}

