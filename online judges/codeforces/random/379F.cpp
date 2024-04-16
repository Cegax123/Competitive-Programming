#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
vector<int> adj[maxn];
int sz[maxn], pi[maxn];
bool block[maxn];
int n;

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

int main() {
	int q; cin >> q;
	
	adj[0].push_back(1);
	adj[0].push_back(2);
	adj[0].push_back(3);

	adj[1].push_back(0);
	adj[2].push_back(0);
	adj[3].push_back(0);

	for(int i = 0; i < q; i++) {
		int v = (i+2) * 2;
		int x; cin >> x;
		x--;
		adj[x].push_back(v);
		adj[v].push_back(x);

		adj[x].push_back(v+1);
		adj[v+1].push_back(x);
	}

	

	return 0;
}
