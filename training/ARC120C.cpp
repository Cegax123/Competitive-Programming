#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int t[4 * maxn];

void update(int v, int tl, int tr, int pos) {
	if(tl == tr) {
		t[v] += 1;
	}
	else {
		int tm = (tl + tr) >> 1;
		if(pos <= tm) update(v * 2, tl, tm, pos);
		else update(v * 2 + 1, tm+1, tr, pos);
		t[v] = t[v * 2] + t[v * 2 + 1];
	}
}

int query(int v, int tl, int tr, int l, int r) {
	if(r < tl or tr < l) return 0;
	if(tl == l and r == tr) return t[v];
	else {
		int tm = (tl + tr) >> 1;

		return query(v * 2, tl, tm, l, min(r, tm)) + 
				query(v * 2 + 1, tm+1, tr, max(tm+1, l), r);
	}
}

int main() {
	int n; cin >> n;
	map<int, vector<int>> posa, posb;
	int a[n], b[n];

	for(int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] += i;
		posa[a[i]].push_back(i);
	}

	for(int i = 0; i < n; i++) {
		cin >> b[i];
		b[i] += i;
		posb[b[i]].push_back(i);
	}

	bool cmp = true;
	for(auto e : posa) {
		if(e.second.size() != posb[e.first].size()) cmp = false;
	}

	for(auto& e : posa) reverse(e.second.begin(), e.second.end());

	if(!cmp) {
		cout << -1 << "\n";
		return 0;
	}

	long long ans = 0;

	for(int i = 0; i < n; i++) {
		int x = posa[b[i]].back(); posa[b[i]].pop_back();
		int off = query(1, 0, n-1, x+1, n-1);

		ans += x+off-i;

		update(1, 0, n-1, x);
	}

	cout << ans << "\n";

	return 0;
}
