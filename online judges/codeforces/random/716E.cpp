#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5+5;

vector<pair<int, int>> adj[maxn];

int n, m;
int ipo[maxn], po[maxn];

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

void gen_po() {
	po[0] = 1;
	for(int i = 1; i < maxn; i++)
		po[i] = po[i-1] * 10ll % m;

	ll iv10, off;
	euclid(10, m, iv10, off);
	iv10 %= m;
	if(iv10 < m) iv10 += m;

	ipo[0] = 1;
	for(int i = 1; i < maxn; i++)
		ipo[i] = ipo[i-1] * 1ll * iv10 % m;
}

const int LOGN = 20;
int timer=0;
int st[maxn], fin[maxn];
int fs[maxn], fe[maxn];
int h[maxn];
int up[maxn][LOGN];

void pre_dfs(int v, int p) {
	st[v] = timer++;

	up[v][0] = p;
	for(int i = 1; i < LOGN; i++)
		up[v][i] = up[up[v][i-1]][i-1];

	if(v == p) h[v] = 0;
	else h[v] = h[p] + 1;

	for(auto [to, d] : adj[v]) if(to != p) {
		fs[to] = (d * 1ll * po[h[v]] % m + fs[v]) % m;
		fe[to] = (fe[v] * 10ll % m + d) % m;

		pre_dfs(to, v);
	}

	fin[v] = timer++;
}

bool is_parent(int u, int v) {
	return st[u] <= st[v] and fin[v] <= fin[u];
}

int lca(int u, int v) {
	if(is_parent(u, v)) return u;
	if(is_parent(v, u)) return v;

	for(int i = LOGN-1; i >= 0; i--) {
		if(!is_parent(up[u][i], v)) u = up[u][i];
	}

	return up[u][0];
}

int sub(int a, int b) {
	int ans = (a-b)%m;
	if(ans < 0) ans += m;
	return ans;
}

int get_path(int u, int v) {
	int p = lca(u, v);

	int L = sub(fs[u], fs[p]) * 1ll * ipo[h[p]] % m * po[h[v]-h[p]] % m;
	int R = sub(fe[v], fe[p] * 1ll * po[h[v]-h[p]] % m);
	return (L+R) % m;
}

int dist(int u, int v) {
	int p =lca(u, v);
	return h[u] + h[v] - 2 * h[p];
}

int sz[maxn], pi[maxn];
bool block[maxn];

vector<int> ct[maxn];

int centroid(int v, int p, int n) {
  sz[v] = 1;
  int mx=0, cen=0;
  for (auto [u, d] : adj[v]) if (u!=p && !block[u]) {
      cen ^= centroid(u, v, n);
      sz[v] += sz[u], mx=max(mx, sz[u]);
  }
  mx = max(mx, n-sz[v]);
  if (2*mx <= n) pi[cen=v]=p;
  return cen;
}

void decompose(int x, int p=-1, int m=n) {
  int cen = centroid(x, -1, m);
  if (~pi[cen]) sz[pi[cen]]=m-sz[cen];
  pi[cen]=p; block[cen]=1;

  if(pi[cen] != -1) ct[pi[cen]].push_back(cen);

  for (auto [v, d] : adj[cen]) if (!block[v]) {
      decompose(v, cen, sz[v]);
  }
}

int root;
ll ans = 0;
ll curr = 0;
map<int, int> mp1, mp2;

void dfs(int u, int p, bool add_to_ans) {
	int val1 = get_path(u, root);
	int val2 = -get_path(root, u) * 1ll * ipo[dist(u, root)] % m;
	if(val2 < 0) val2 += m;

	assert(val1 >= 0 and val1 < m);
	assert(val2 >= 0 and val2 < m);

	if(add_to_ans) {
		curr += mp1[val2];
		curr += mp2[val1];
	}
	else {
		mp1[val1]++;
		mp2[val2]++;
	}

	for(int to : ct[u]) if(to != p) {
		dfs(to, u, add_to_ans);
	}
}

void calc(int v, int p=-1) {
	root = v;

	curr = 0;
	mp1.clear(); mp2.clear();

	mp1[0]++; mp2[0]++;

	for(int to : ct[v]) if(to != p) {
		dfs(to, v, 1);
		dfs(to, v, 0);
	}


	ans += curr;

	for(int to : ct[v]) if(to != p) {
		calc(to, v);
	}
}


int main() {
	cin >> n >> m;
	for(int i = 0; i < n-1; i++) {
		int u, v, d; cin >> u >> v >> d;
		adj[u].push_back({v, d});
		adj[v].push_back({u, d});
	}

	gen_po();
	pre_dfs(0, 0);
	decompose(0);

	//for(int i = 0; i < n; i++) {
		//cout << i << " " << pi[i] << "\n";
	//}

	int root = 0;
	for(int i = 0; i < n; i++)
		if(pi[i] == -1) root = i;

	calc(root);

	cout << ans << "\n";

	return 0;
}

