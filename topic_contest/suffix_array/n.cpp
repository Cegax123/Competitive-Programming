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
const int LOGN = 20;
const ll mod = 1e9+7;

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

const int k = 3;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s[k];
	int n = 0;
	int x = maxn;
	for(int i = 0; i < k; i++) {
		cin >> s[i];
		n += s[i].size() + 1;
		x = min(x, (int) s[i].size());
	}

	vi v(n), c(n);
	int ind = 0;
	for(int i = 0; i < k; i++) {
		for(int j = 0; j < (int) s[i].size(); j++) {
			v[ind + j] = s[i][j];
			c[ind + j] = i;
		}

		v[ind + s[i].size()] = i;
		c[ind + s[i].size()] = -1;

		ind += s[i].size() + 1;
	}

	vi a = suffix_array(v), lcp = lcp_array(v, a);

	LCP_build(lcp);
	vector<vi> nxt(n, vi(k, n));
	vector<vi> sum(n, vi(k, 0));

	for(int i = n-1; i >= 0; i--) {
		for(int j = 0; j < k; j++) 
			if(i+1 < n) nxt[i][j] = nxt[i+1][j];

		if(c[a[i]] >= 0) {
			nxt[i][c[a[i]]] = i;
			sum[i][c[a[i]]]++;
		}
	}

	for(int i = 0; i < k; i++) {
		for(int j = 1; j < n; j++) {
			sum[j][i] += sum[j-1][i];
		}
	}

	int go[n];

	for(int i = 0; i < n; i++) {
		go[i] = -1;
		for(int j = 0; j < k; j++) {
			go[i] = max(go[i], nxt[i][j]);
		}
	}
	
	vector<set<int>> banned(n);
	ll cnt[maxn];
	memset(cnt, 0, sizeof(cnt));

	for(int i = 0; i < n; i++) {
		if(lcp[i] == 0 or c[a[i]] == -1) continue;

		int l = 0, r = i;

		while(l < r) {
			int m = (l + r + 1) >> 1;
			
			if(LCP(m, i+1) < lcp[i]) l = m;
			else r = m-1;
		}

		int L = l;
		if(banned[L].count(lcp[i])) continue;
		banned[L].insert(lcp[i]);


		l = i, r = n;

		while(l < r) {
			int m = (l + r) >> 1;

			if(LCP(i, m) < lcp[i]) r = m;
			else l = m + 1;
		}

		int R = l;


		int repeated = max(LCP(L, i+1), LCP(i, R));
		ll add = 1;

		// cout << i << " "  << lcp[i] << " " << repeated << " " << L << " " << R << endl;
		for(int j = 0; j < k; j++) 
			add = add * ((ll) sum[R-1][j] - sum[L][j]) % mod;
		
		cnt[repeated + 1] = (cnt[repeated + 1] + add)%mod;
		cnt[lcp[i]+1] = (cnt[lcp[i]+1] - add)%mod;
	}

	for(int i = 1; i < maxn; i++) {
		cnt[i] = (cnt[i] + cnt[i-1])%mod;
		if(cnt[i] < 0) cnt[i] += mod;
	}

	for(int i = 1; i <= x; i++)
		cout << cnt[i] << " ";

    return 0;
}


