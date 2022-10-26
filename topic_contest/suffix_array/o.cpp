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

vector<int> z_function(const string& s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}


const int maxn = 2e5+500;
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

vi find_ocurr(const string& s, const string& t) {
    vi v;
    for(char c : s) v.pb(c);
    v.pb(0);
    for(char c : t) v.pb(c);
	v.pb(-1);

    vi a = suffix_array(v), lcp = lcp_array(v, a);
	LCP_build(lcp);

	// for(int i = 0; i < (int) a.size(); i++)
	//     cout << a[i] << endl;

    vi ans(t.size(), 0);

	int n = v.size();
	BIT ft(n);

	for(int i = 0; i < n; i++) 
		if(a[i] < (int) s.size()) 
			ft.add(i, 1);

	for(int i = 0; i < n; i++) {
		if(a[i] <= (int) s.size() or a[i] == n-1) continue;
		int len = n-a[i]-1;
		int l = 0, r = i-1;

		while(l < r) {
			int m = (l + r) >> 1;
			if(LCP(m, i) >= len) r = m;
			else l = m + 1;
		}

		int L = (l < i and LCP(l, i) >= len ? l : i);

		l = i + 1, r = n-1;
		while(l < r) {
			int m = (l+r+1) >> 1;
			if(LCP(i, m) >= len) l = m;
			else r = m-1;
		}

		int R = (l > i and LCP(i, l) >= len ? l : i);

		ans[a[i]-s.size()-1] = ft.sum(L, R);

		// cout << a[i]-s.size()-1 << " " << ans[a[i]-s.size()-1] << " " << len << " " << L << " " << R;
		// cout << endl;
	}

	reverse(all(ans));
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s, t; cin >> s >> t;

    string tmp = t + "$" + t;
    vi z_t = z_function(tmp);

    string tmp2 = s + "$" + t;
    vi ztmp = z_function(tmp2);

	reverse(all(s));
	reverse(all(t));
	
	vi ocurr = find_ocurr(s, t);

    for(int i = 0; i < ztmp[s.size() + 1]; i++) 
		ocurr[i]--;

	for(int i = 0; i < (int) t.size(); i++)
		cout << ocurr[i] << " ";

	cout << endl;

	ll ans = (ll) s.size() * t.size();

	for(int i = 0; i < (int) t.size()-1; i++) {
		ans -= (ll) min(z_t[i+1], i + 1) * ocurr[i];
	}

	cout << ans << "\n";
    
    return 0;
}


