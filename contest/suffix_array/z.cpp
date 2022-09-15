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
const int LOGN = 20;

int LCP_ST[maxn][LOGN];

void LCP_build(const vector<int>& lcp) {
    for(int i = 1; i <= (int) lcp.size(); i++) 
        LCP_ST[i][0] = lcp[i-1];

    for(int k = 1; (1 << k) <= (int) lcp.size(); k++) {
        int dis = 1 << (k-1);

        for(int i = 1; i + 2*dis -1 <= (int) lcp.size(); i++)
            LCP_ST[i][k] = min(LCP_ST[i][k-1], LCP_ST[i+dis][k-1]);
    }
}

int LCP(int L, int R) {
    L++;

    int d = R-L+1;
    int k = 31- __builtin_clz(d);
    int dis = 1 << k;

    return min(LCP_ST[L][k], LCP_ST[R-dis+1][k]);
}

vector<int> lcp_array(vector<int> &s, vector<int> &a){
	int n = s.size();
	vector<int> rank(n);
	for(int i = 0; i < n; i++) rank[a[i]] = i;
	int k = 0;
	vector<int> lcp(n);
	for(int i = 0; i < n; i++){
		if(rank[i] + 1 == n){
			k = 0;
			continue;
		}
		int j = a[rank[i] + 1];
		while(i + k < n and j + k < n and s[i + k] == s[j + k]) k++;
		lcp[rank[i]] = k;
		if(k) k--;
	}
	return lcp;
}

vector<int> suffix_array(vector<int> &s){
	int n = s.size();
	vector<int> a(n);
	vector<int> mapeo(n);
	iota(a.begin(), a.end(), 0);
	sort(a.begin(), a.end(), [&] (int i, int j){
		return s[i] < s[j];
	});
	mapeo[a[0]] = 0;
	for(int i = 1; i < n; i++){
		mapeo[a[i]] = mapeo[a[i - 1]] + (s[a[i - 1]] != s[a[i]]);
	}
	int len = 1;
	vector<int> head(n);
	vector<int> new_mapeo(n);
	vector<int> sorted_by_second(n);
	while(len < n){
		for(int i = 0; i < n; i++) sorted_by_second[i] = (a[i] - len + n) % n;
		for(int i = n - 1; i >= 0; i--) head[mapeo[a[i]]] = i;
		for(int i = 0; i < n; i++){
			int x = sorted_by_second[i];
			a[head[mapeo[x]]++] = x;
		}
		new_mapeo[a[0]] = 0;
		for(int i = 1; i < n; i++){
			if(mapeo[a[i - 1]] != mapeo[a[i]]){
				new_mapeo[a[i]] = new_mapeo[a[i - 1]] + 1;
			}
			else{
				int pre = mapeo[(a[i - 1] + len) % n];
				int cur = mapeo[(a[i] + len) % n];
				new_mapeo[a[i]] = new_mapeo[a[i - 1]] + (pre != cur);
			}
		}
		swap(mapeo, new_mapeo);
		len <<= 1;
	}
	return a;
}

struct Query {
	int l, r, id;
};

int t[4 * maxn];

void update(int v, int tl, int tr, int pos) {
	if(tl == tr) {
		t[v] = 1;
	}
	else {
		int tm = (tl + tr) >> 1;
		if(pos <= tm) update(v * 2, tl, tm, pos);
		else update(v * 2 + 1, tm+1, tr, pos);

		t[v] = t[v * 2] + t[v * 2 + 1];
	}
}

int query(int v, int tl, int tr, int l, int r) {
	if(tr < l or r < tl) return 0;
	if(tl == l and tr == r) {
		return t[v];
	}
	else {
		int tm = (tl + tr) >> 1;
		return query(v * 2, tl, tm, l, min(r, tm)) +
				query(v * 2 + 1, tm+1, tr, max(tm+1, l), r);
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
	int h[n];

	for(int i = 0; i < n; i++)
		cin >> h[i];

	const int INF = 2e9;

	vi s;
	for(int i = 0; i < n-1; i++)
		s.pb(h[i+1]-h[i]);

	s.pb(-INF);

	for(int i = 0; i < n-1; i++)
		s.pb(-s[i]);

	s.pb(-INF-1);

	vi a = suffix_array(s), lcp = lcp_array(s, a);
	LCP_build(lcp);

	vi pos(a.size());

	for(int i = 0; i < (int) a.size(); i++)
		pos[a[i]] = i;


	vector<Query> rq[n], lq[n];

	int q; cin >> q;

	int ans[q];
	memset(ans, 0, sizeof(ans));

	for(int tc = 0; tc < q; tc++) {
		int l, r; cin >> l >> r;
		l--; r--;

		int len = r-l+1;
		int L, R;

		if(l == r) {
			ans[tc] = n-1;
		}
		else {
			int al = 0, ar = pos[l+n]-1;

			while(al < ar) {
				int am = (al + ar) >> 1;
				if(LCP(am, pos[l+n]) >= len-1) ar = am;
				else al = am+1;
			}

			L = (LCP(al, pos[l+n]) >= len-1 ? al : pos[l+n]);

			al = pos[l+n]+1, ar = a.size()-1;
			
			while(al < ar) {
				int am = (al + ar + 1) >> 1;
				if(LCP(pos[l+n], am) >= len-1) al = am;
				else ar = am-1;
			}

			R = (LCP(pos[l+n], al) >= len-1 ? al : pos[l+n]);

			//cout << L << " " << R << endl;

			if(r+1 < n-1) rq[r+1].pb({L, R, tc});
			if(l-len >= 0) lq[l-len].pb({L, R, tc});
		}
	}

	//for(int x : a)
		//cout << x << " ";
	//cout << endl;

	for(int i = n-2; i >= 0; i--) {
		update(1, 0, a.size(), pos[i]);

		for(Query Q : rq[i]) 
			ans[Q.id] += query(1, 0, a.size(), Q.l, Q.r);
	}

	memset(t, 0, sizeof(t));

	for(int i = 0; i < n-1; i++) {
		update(1, 0, a.size(), pos[i]);

		for(Query Q : lq[i])
			ans[Q.id] += query(1, 0, a.size(), Q.l, Q.r);
	}

	for(int i = 0; i < q; i++)
		cout << ans[i] << "\n";

    return 0;
}


