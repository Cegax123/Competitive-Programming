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

const int maxn = 3e5+5;

ii t[8*maxn], lazy[8*maxn];
ii nill = {0, -1};

void build(int v, int tl, int tr) {
		if(tl == tr) {
				t[v] = lazy[v] = nill;
		}
		else {
				int tm = (tl+tr)>>1;
				build(v*2, tl, tm);
				build(v*2+1, tm+1, tr);
				
				t[v] = lazy[v] = nill;
		}
}

void push(int v) {
		if(lazy[v] == nill) return;

		t[v*2] = max(t[v*2], lazy[v]);
		lazy[v*2] = max(lazy[v*2], lazy[v]);
		t[v*2+1] = max(t[v*2+1], lazy[v]);
		lazy[v*2+1] = max(lazy[v*2+1], lazy[v]);

		lazy[v] = nill;
}

void update(int v, int tl, int tr, int l, int r, ii x) {
		if(l > tr or r < tl) return;
		if(l == tl and r == tr) {
				t[v] = x;
				lazy[v] = x;
		}
		else {
				push(v);
				int tm = (tl+tr)>>1;
				update(v*2, tl, tm, l, min(r, tm), x);
				update(v*2+1, tm+1, tr, max(tm+1, l), r, x);

				t[v] = max(t[v*2], t[v*2+1]);
		}
}

ii query(int v, int tl, int tr, int l, int r) {
		if(l > tr or r < tl) return nill;
		if(l == tl and r == tr) {
				return t[v];
		}
		else {
				push(v);
				int tm = (tl+tr)>>1;

				return max(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(tm+1, l),r));
		}
}

int main() {
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int n, m; cin >> n >> m;

		map<int, int> mp;
		set<int> s;
		vii v[maxn];

		for(int i = 0; i < m; i++) {
				int id, l, r; cin >> id >> l >> r;
				id--;
				v[id].pb({l, r});

				s.insert(l);
				s.insert(r);
		}

		int ind = 0;

		for(auto x : s) {
				mp[x] = ind++;
		}

		for(int i = 0; i < n; i++) {
				for(auto& it : v[i]) {
						it.first = mp[it.first];
						it.second = mp[it.second];
				}
		}

		vi prev(n);
		int k = s.size();
		build(1, 0, k-1);

		for(int i = 0; i < n; i++) {
				ii x = nill;
				for(auto& it : v[i]) {
						x = max(x, query(1, 0, k-1, it.first, it.second));
				}

				prev[i] = x.second;

				x.first++;
				x.second = i;

				for(auto& it : v[i]) {
						update(1, 0, k-1, it.first, it.second, x);
				}
		}


		ii x = query(1, 0, k-1, 0, k-1);
		
		bool vis[n];
		memset(vis, 0, sizeof(vis));

		int cur = x.second;
		while(cur != -1) {
				vis[cur] = 1;
				cur = prev[cur];
		}
				
		cout << n-x.first << "\n";

		for(int i = 0; i < n; i++) {
				if(!vis[i]) cout << i+1 << " ";
		}

		return 0;
}

