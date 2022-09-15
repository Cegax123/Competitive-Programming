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

const int maxn = 1e5;

int t[4*maxn+5], lazy[4*maxn+5];

void push(int v) {
	t[2*v] += lazy[v];
	t[2*v+1] += lazy[v];

	lazy[2*v] += lazy[v];
	lazy[2*v+1] += lazy[v];

	
	lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int x) {
	if(tl > r or tr < l) 
		return;
	if(tl == l and tr == r) {
		t[v] += x;
		lazy[v] += x;
	}
	else {
		push(v);

		int tm = (tl+tr) >> 1;

		update(v*2, tl, tm, l, min(r, tm), x);
		update(v*2+1, tm+1, tr, max(l, tm+1), r, x);

		t[v] = min(t[v*2], t[v*2+1]);
	}
}

int query(int v, int tl, int tr, int pos) {
	if(tl == tr)
		return t[v];
	else {
		push(v);
		int tm = (tl+tr)/2;
		
		if(pos <= tm) return query(v*2, tl, tm, pos);
		else return query(v*2+1, tm+1, tr, pos);
	}
}

int n, m;
int a[maxn];
vector<ll> sum, avg;
vector<vi> b;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int q; cin >> q;
	while(q--) {
		cin >> n >> m;

		for(int i = 0; i < n; i++) {
			cin >> a[i];
			update(1, 0, maxn, 0, a[i], 1);
		}

		sum.clear(); sum.resize(m, 0);
		avg.clear(); avg.resize(m);
		b.clear(); b.resize(m);

		for(int i = 0; i < m; i++) {
			int k; cin >> k;
			b[i].resize(k);

			for(int j = 0; j < k; j++) {
				cin >> b[i][j];
				sum[i] += b[i][j];
			}

			avg[i] = (sum[i] + k - 1) / k;

			update(1, 0, maxn, 0, avg[i], -1);
		}

		for(int i = 0; i < m; i++) {
			int k = b[i].size();

			for(int j = 0; j < k; j++) {
				ll new_avg = (sum[i] - b[i][j] + k - 2) / (k-1);

				update(1, 0, maxn, 0, avg[i], 1);
				update(1, 0, maxn, 0, new_avg, -1);

				if(t[1] < 0) cout << "0";
				else cout << "1";

				update(1, 0, maxn, 0, avg[i], -1);
				update(1, 0, maxn, 0, new_avg, 1);
			}
		}

		for(int i = 0; i < n; i++)
			update(1, 0, maxn, 0, a[i], -1);

		for(int i = 0; i < m; i++)
			update(1, 0, maxn, 0, avg[i], 1);

		cout << "\n";
	}
	
	return 0;
}

