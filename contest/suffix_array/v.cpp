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

int n, k;

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

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;

    int id[maxn];
	int sz_suff[maxn];
    memset(id, -1, sizeof(id));

    vi s;
    int tmp = 0;

    for(int i = 0; i < n; i++) {
        string x; cin >> x;
        for(int j = 0; j < (int) x.size(); j++) {
            s.pb(x[j]);
			sz_suff[tmp] = x.size()-j;
            id[tmp++] = i;
        }
        s.pb(-i);
        tmp++;
    }

    vi a = suffix_array(s), lcp = lcp_array(s, a);
	LCP_build(lcp);

	const int INF = 1e9;
	vi R(maxn, INF);
	
	int cnt[n];
	memset(cnt, 0, sizeof(cnt));

	int r = 0;
	int used = 0;

	for(int i = 0; i < (int) a.size(); i++) {
		if(r < i) r = i;
		while(used < k and r < (int) a.size()) {
			if(id[a[r]] == -1) {
				r++;
				continue;
			}
			
			if(cnt[id[a[r]]] == 0) used++;
			cnt[id[a[r]]]++;

			r++;
		}

		if(used < k) break;

		R[i] = r-1;

		if(id[a[i]] != -1) {
			cnt[id[a[i]]]--;
			if(cnt[id[a[i]]] == 0) used--;
		}
	}

	auto f = [&] (int suff, int len) {
		int l = 0, r = suff-1;

		while(l < r) {
			int m = (l + r) >> 1;
			if(LCP(m, suff) >= len) r = m;
			else l = m + 1;
		}

		int tl = (LCP(l, suff) >= len ? l : suff);

		l = suff+1, r = (int) a.size()-1;

		while(l < r) {
			int m = (l + r + 1) >> 1;
			if(LCP(suff, m) >= len) l = m;
			else r = m - 1;
		}

		int tr = (LCP(suff, l) >= len ? l : suff);

		return R[tl] <= tr;
	};

	ll ans[n];
	memset(ans, 0, sizeof(ans));
	for(int i = 0; i < (int) a.size(); i++) {
		if(id[a[i]] == -1) continue;

		int l = 1, r = sz_suff[a[i]];

		while(l < r) {
			int m = (l + r + 1) >> 1;
			if(f(i, m)) l = m;
			else r = m-1;
		}

		if(f(i, l)) ans[id[a[i]]] += l;
	}

	for(int i = 0; i < n; i++)
		cout << ans[i] << " ";
	
    return 0;
}


