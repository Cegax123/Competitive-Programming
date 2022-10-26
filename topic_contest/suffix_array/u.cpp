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

const int maxk = 10;
const int maxn = 5e5+5e4+100;
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
    vi vs, id;

    auto add_string = [&] (const string& s, int ids) {
        for(char c : s) {
            vs.pb(c);
            id.pb(ids);
        }
        vs.pb(200);
        id.pb(-1);
    };

    string s; cin >> s;
    add_string(s, 0);

    int k; cin >> k;
    string p[k+1];
    int lp[k+1], rp[k+1];

    for(int i = 1; i <= k; i++) {
        cin >> p[i] >> lp[i] >> rp[i];
        add_string(p[i], i);
    }
    
    vs.pb(0);
    id.pb(-1);
	
    vi a = suffix_array(vs), lcp = lcp_array(vs, a);
    LCP_build(lcp);

	int cnt[maxn][maxk+1];
	memset(cnt, 0, sizeof(cnt));

	for(int i = 1; i <= k; i++) {
		if(id[a[0]] == i) cnt[0][i] = 1;
		for(int j = 1; j < (int) a.size(); j++) {
			cnt[j][i] = cnt[j-1][i] + (id[a[j]] == i);
		}
	}

	auto comp = [&] (int pos_suff, int len, char op) {
		int l = 0, r = pos_suff-1;

		while(l < r) {
			int m = (l + r) >> 1;
			if(LCP(m, pos_suff) >= len) r = m;
			else l = m + 1;
		}

		int L = (LCP(l, pos_suff) >= len ? l : pos_suff);

		l = pos_suff + 1, r = a.size()-1;

		while(l < r) {
			int m = (l + r + 1) >> 1;
			if(LCP(pos_suff, m) >= len) l = m;
			else r = m-1;
		}

		int R = (LCP(pos_suff, r) >= len ? r : pos_suff);

		bool cmp = 1;
		if(op == 'L') {
			for(int i = 1; i <= k; i++) {
				if(cnt[R][i] - cnt[L-1][i] < lp[i]) cmp = 0;
			}
		}
		else {
			for(int i = 1; i <= k; i++) {
				if(cnt[R][i] - cnt[L-1][i] > rp[i]) cmp = 0;
			}
		}

		return cmp;
	};

	int pos;
	for(int i = 0; i < (int) a.size(); i++) {
		if(a[i] == 0) pos = i;
	}

	vii inter(s.size());

	for(int i = 0; i < (int) a.size(); i++) {
		if(id[a[i]] != 0) continue;
		int l = 1, r = s.size()-a[i];

		while(l < r) {
			int m = (l + r + 1) >> 1;
			if(comp(i, m, 'L')) l = m;
			else r = m-1;
		}

		int R = (comp(i, l, 'L') ? l : -1);

		l = 1, r = s.size()-a[i];

		while(l < r) {
			int m = (l + r) >> 1;
			if(comp(i, m, 'R')) r = m;
			else l = m+1;
		}

		int L = (comp(i, l, 'R') ? r : -1);

		inter[a[i]] = {L, R};
	}

	vs.clear();

	for(char c : s) vs.pb(c);
	vs.pb(0);

	a = suffix_array(vs), lcp = lcp_array(vs, a);
	LCP_build(lcp);

	int ans = 0;
	for(int i = 0; i < (int) a.size(); i++) {
		int x = a[i];

		if(x >= s.size() or inter[x].first > inter[x].second or inter[x].first == -1 or inter[x].second == -1) continue;

		int used = lcp[i-1];
		if(used < inter[x].first) ans += inter[x].second-inter[x].first+1;
		else if(used <= inter[x].second) ans += inter[x].second-used;
	}

	cout << ans << "\n";

    return 0;
}



