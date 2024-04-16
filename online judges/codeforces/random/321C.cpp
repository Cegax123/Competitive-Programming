#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
vector<int> adj[maxn];
int sz[maxn], pi[maxn];
bool block[maxn];
int n;
int officer[maxn];

int centroid(int v, int p, int n) {
  sz[v] = 1;
  int mx=0, cen=0;
  for (auto u : adj[v]) if (u!=p && !block[u]) {
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
  for (auto v : adj[cen]) if (!block[v]) {
      decompose(v, cen, sz[v]);
  }
}

int get_officer(int v) {
	if(officer[v]) return officer[v];

	if(pi[v] == -1) {
		return officer[v] = 1;
	}
	else {
		return officer[v] = get_officer(pi[v]) + 1;
	}
}

int main() {
	cin >> n;

	for(int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	decompose(0);

	for(int i = 0; i < n; i++) {
		char c = 'A' + get_officer(i)-1;
		cout << c << " ";
	}

	return 0;
}
