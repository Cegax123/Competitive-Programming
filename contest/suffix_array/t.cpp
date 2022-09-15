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
    vector<ll> bit;  // binary indexed tree
    int n;

    BIT(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    BIT(vector<ll> a) : BIT(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    ll sum(int r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    ll sum(int l, int r) {
        if(l > r) return 0;
        return sum(r) - sum(l - 1);
    }

    void add(int idx, ll delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ifstream in("curse.in");

	int t; in >> t;
    for(int tc = 1; tc <= t; tc++) {
        string s[2];
        in >> s[0] >> s[1];

        vi v;

        for(int i = 0; i < 2; i++) {
            for(char c : s[i]) 
                v.pb(c);

            v.pb(-i);
        }

        vi a = suffix_array(v), lcp = lcp_array(v, a);
        LCP_build(lcp);
        int n = s[0].size() + 1 + s[1].size() + 1;
        vi back(n, -1);

        for(int i = 0; i < n; i++) {
            if(i) back[i] = back[i-1];
            if(a[i] > (int) s[0].size() and a[i] < n-1) 
                back[i] = i;
        }

        vi nxt(n, n);

        for(int i = n-1; i >= 0; i--) {
            if(i+1 < n) nxt[i] = nxt[i+1];
            if(a[i] > (int) s[0].size() and a[i] < n-1) 
                nxt[i] = i;
        }

        int k = s[0].size();
        vi c(s[0].size(), 0);

        for(int i = 0; i < n; i++) {
            if(a[i] < (int) s[0].size()) {
                if(back[i] >= 0) {
                    c[a[i]] = max(c[a[i]], LCP(back[i], i));
                }
                if(nxt[i] < n) {
                    c[a[i]] = max(c[a[i]], LCP(i, nxt[i]));
                }
            }
        }


        int q; in >> q;
        vii queries[k];

        for(int i = 0; i < q; i++) {
            int l, r; in >> l >> r;
            l--; r--;

            queries[r].pb({l, i});
        }

        ll ans[q];

        BIT comp(k), sum(k);
        vi tmp[k];
        
        for(int i = 0; i < k; i++) {
            if(c[i] > 0) {
                comp.add(i, 1);
                tmp[i + c[i] - 1].pb(i);
            }

            for(int x : tmp[i]) {
                comp.add(x, -1);
                sum.add(x, c[x]);
            }

            for(auto e : queries[i]) {
                int l = e.first, id = e.second;
                int cnt = comp.sum(l, i);
                ans[id] = cnt * 1ll * (i-l+1) + sum.sum(l, i);
            }
        }

        cout << "Case " << tc << ":\n";
        for(int i = 0; i < q; i++)
            cout << ans[i] << "\n";
    }

	
	
    return 0;
}


