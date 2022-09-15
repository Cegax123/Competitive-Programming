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
const int INF = 1e9;

int t[4*maxn];
int a[maxn];

void build(int v, int tl, int tr) {
	if(tl == tr) 
		t[v] = a[tl];
	else {
		int tm = (tl+tr) >> 1;

		build(v*2, tl, tm);
		build(v*2+1, tm+1, tr);

		t[v] = min(t[v*2], t[v*2+1]);
	}
}

int query(int v, int tl, int tr, int l, int r) {
	if(l > r)
		return INF;
	if(tl == l and tr == r)
		return t[v];
	else {
		int tm = (tl+tr) >> 1;

		return min(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int q; cin >> q;
	for(int tc = 1; tc <= q; tc++) {
		int n; cin >> n;
		for(int i = 0; i < n; i++)
			cin >> a[i];

		int maxR[n];
		
		maxR[n-1] = a[n-1];
		for(int i = n-2; i >= 0; i--) 
			maxR[i] = max(maxR[i+1], a[i]);
		
		build(1, 0, n-1);

		int maxL = -1;
		bool found = false;
		int x, y, z;

		for(int i = 0; i < n-2; i++) {
			maxL = max(maxL, a[i]);

			int l = i+2, r = n-1;

			while(l < r) {
				int m = (l+r+1) >> 1;
				if(maxR[m] < maxL) r = m-1;
				else l = m;
			}

			if(maxR[l] != maxL) continue;
			
			int R = l;


			l = i+2, r = R;

			while(l < r) {
				int m = (l+r) >> 1;
				if(maxR[m] == maxL) r = m;
				else l = m+1;
			}

			int L = l;

			l = L, r = R;

			while(l < r) {
				int m = (l+r) >> 1;
				int Q = query(1, 0, n-1, i+1, m-1);
				if(Q > maxL) l = m+1;
				else r = m;
			}

			if(query(1, 0, n-1, i+1, l-1) == maxL) {
				found = 1; 
				x = i+1; y = l-i-1; z = n-l;
				break;
			}
		}
	
		if(found) cout << "YES\n" << x << " " << y << " " << z << "\n";
		else cout << "NO\n";
	}
	
	return 0;
}

