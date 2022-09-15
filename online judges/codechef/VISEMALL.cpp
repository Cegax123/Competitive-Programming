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

const int maxn = 5e5+5;

int t[4*maxn], cha[4*maxn], sz[4*maxn];
string s;

void build(int v, int tl, int tr) {
	if(tl == tr) {
		t[v] = s[tl]-'0';
		sz[v] = 1;
	}
	else {
		int tm = (tl + tr) >> 1;
		build(v*2, tl, tm);
		build(v*2+1, tm+1, tr);

		t[v] = t[v*2] + t[v*2+1];
		sz[v] = sz[v*2] + sz[v*2+1];
	}
}

void push(int v) {
	if(cha[v]) {
		t[v*2] = sz[v*2]-t[v*2];
		t[v*2+1] = sz[v*2+1]-t[v*2+1];

		cha[v*2] = 1-cha[v*2];
		cha[v*2+1] = 1-cha[v*2+1];

		cha[v] = 0;
	}
}

void update(int v, int tl, int tr, int l, int r) {
	if(tr < l or r < tl) return;

	if(tl == l and tr == r) {
		t[v] = sz[v]-t[v];
		cha[v] = 1-cha[v];
	}
	else {
		push(v);

		int tm = (tl+tr) >> 1;
		update(v*2, tl, tm, l, min(r, tm));
		update(v*2+1, tm+1, tr, max(l, tm+1), r);
		t[v] = t[v*2] + t[v*2+1];
	}
}

int query(int v, int tl, int tr, int l, int r) {
	if(tr < l or r < tl) return 0;

	if(tl == l and tr == r) {
		return t[v];
	}

	else {
		push(v);

		int tm = (tl+tr) >> 1;

		return query(v*2, tl, tm, l, min(r, tm)) + 
				query(v*2+1, tm+1, tr, max(l, tm+1), r);
	}
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q; cin >> n >> q;
    cin >> s;

    build(1, 0, n-1);

    while(q--) {
    	int op; cin >> op;

    	if(op == 2) {
    		int l, r, x; cin >> l >> r >> x;
    		l--; r--; x--;

    		int len = r-l+1;
    		int cnt1 = query(1, 0, n-1, l, r);
    		int cnt0 = len-cnt1;

    		if(cnt1 == 0 or cnt1 == len) {
    			if(x == l) cout << "YES\n";
    			else cout << "NO\n";
    			continue;
    		}

    		if(query(1, 0, n-1, l, l+cnt1-1) == cnt1) {
    			if(x != l+cnt1) cout << "NO\n";
    			else cout << "YES\n";
    			continue;
    		}

    		if(query(1, 0, n-1, l, l+cnt0-1) == 0) {
    			if(x != l+cnt0) cout << "NO\n";
    			else cout << "YES\n";
    			continue;
    		}

    		cout << "YES\n";
    	}
    	else {
    		int l, r; cin >> l >> r;
    		l--; r--;

    		update(1, 0, n-1, l, r);
    	}
    }
	
    return 0;
}
