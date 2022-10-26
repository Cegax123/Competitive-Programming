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

int n;

const int maxn = 4e5+500;
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

struct BIT {
    vector<int> bit;  // binary indexed tree
    int n;

    BIT(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    BIT(vector<int> a) : BIT(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        if(l > r) return 0;
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int k, q; cin >> k >> q;
    string t[k];

    vi v, id;
	
    for(int i = 0; i < k; i++) {
        cin >> t[i];

        for(char c : t[i]) {
            v.pb(c);
            id.pb(i);
        }

        v.pb(-i);
        id.pb(-1);

        n += t[i].size() + 1;
    }

    vi a = suffix_array(v), lcp = lcp_array(v, a);
    LCP_build(lcp);
    vi pos[k], st(k, n), g(k, n);

    for(int i = 0; i < n; i++) {
        if(id[a[i]] != -1) {
            int curr = id[a[i]];
            pos[curr].pb(i);
            if(g[curr] > a[i]) {
                g[curr] = a[i];
                st[id[a[i]]] = i;
            }
        }
    }
   
    vector<int> ans(q, 0);

    vii L[k], R[k];
    vi T[k];

    for(int i = 0; i < q; i++) {
        int l, r, j; cin >> l >> r >> j;
        l--; r--; j--;

        T[j].pb(i);
        if(l-1 >= 0) 
            L[l-1].pb({j, i});

        if(r+1 < k)
            R[r+1].pb({j, i});
    }

    vii ind(k);

    for(int i = 0; i < k; i++) {
        int p = st[i];
        int l = 0, r = p-1;

        while(l < r) {
            int m = (l + r) >> 1;
            if(LCP(m, p) >= (int) t[i].size()) r = m;
            else l = m+1;
        }

        int sl = (LCP(l, p) >= (int) t[i].size() ? l : p);

        l = p+1, r = n-1;

        while(l < r) {
            int m = (l + r + 1) >> 1;
            if(LCP(p, m) >= (int) t[i].size()) l = m;
            else r = m-1;
        }

        int sr = (LCP(p, l) >= (int) t[i].size() ? l : p);

        ind[i].first = sl; ind[i].second = sr;

        for(int x : T[i])
            ans[x] += sr-sl+1;
    }

    BIT arrL(n);

    for(int i = 0; i < k; i++) {
        for(int x : pos[i])
            arrL.add(x, 1);

        for(auto e : L[i]) {
            int j = e.first, idq = e.second;
            ans[idq] -= arrL.sum(ind[j].first, ind[j].second);
        }
    }


    BIT arrR(n);

    for(int i = k-1; i >= 0; i--) {
        for(int x : pos[i])
            arrR.add(x, 1);

        for(auto e : R[i]) {
            int j = e.first, idq = e.second;
            ans[idq] -= arrR.sum(ind[j].first, ind[j].second);
        }
    }

    for(int i = 0; i < q; i++)
        cout << ans[i] << "\n";
	
    return 0;
}


