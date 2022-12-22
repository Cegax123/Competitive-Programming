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

const int E = 26;

const int maxn = 5e5+5;
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

int len[maxn];

int LCP(int L, int R) {
	if(L == R) return len[L];

	if(R < L) swap(L, R);
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
    int n; cin >> n;

    vector<string> s(1);
    cin >> s[0];

    vi c(E);
    for(int i = 0; i < E; i++) {
        cin >> c[i];
	}

    int k; cin >> k;

    for(int i = 0; i < k; i++) {
        string t; cin >> t;
        s.pb(t);
    }

    vi idx(k+1);
    iota(all(idx), 0);

    sort(all(idx), [&](int i, int j) {
            return s[i] < s[j];
            });

    vi init(k+1);
    vi vs;

    for(int i = 0; i <= k; i++) {
        init[i] = vs.size();

        for(char c : s[i])
            vs.pb(c);

        vs.pb(-i);
    }

	vi a = suffix_array(vs), lcp = lcp_array(vs, a);
	LCP_build(lcp);

	vi pos(a.size());
	for(int i = 0; i < (int) a.size(); i++)
		pos[a[i]] = i;

	vi pidx(idx.size());
	for(int i = 0; i <= k; i++) {
		pidx[i] = pos[init[idx[i]]];
	}
	pidx.pb(0);

	for(int i = 0; i <= k; i++) {
		len[pos[idx[i]]] = s[idx[i]].size();
	}

	bool ans[k+1];
	memset(ans, 0, sizeof(ans));

	int st = -1;
	for(int i = 0; i <= k; i++) {
		if(LCP(pos[0], pidx[i]) == n and (int) s[idx[i]].size() == n) {
			if(st == -1) {
				ans[i] = 1;
			}
			st = i;
		}
	}

	for(int i = st; i <= k; i++) {
		if(LCP(pos[0], pidx[i]) < n) break;
		int L = (i == k ? 0 : LCP(pidx[i], pidx[i+1]));
		if(L == (int) s[idx[i]].size() and L == (int) s[idx[i+1]].size()) continue;
		
		vi tmp = c;

		for(int t = n; t < L; t++) 
			tmp[s[idx[i]][t]-'a']--;

		bool cmp = 1;
		for(int t = 0; t < E; t++)
			if(tmp[t] < 0) cmp = 0;

		if(cmp == 0) continue;

		s[idx[i]].pb('a'-1);

		bool found = false;
		for(int t = max(n, L); t < (int) s[idx[i]].size(); t++) {
			int lmt = E-1;
			if(t == L and L >= n) lmt = s[idx[i+1]][t]-'a';

			int init = s[idx[i]][t]-'a';

			bool flag = 0;
			for(int y = init+1; y <= lmt; y++) {
				if(tmp[y]) flag = 1;
			}

			if(flag == 1) {
				found = 1;
				break;
			}
				
			if(tmp[init] == 0) break;
			tmp[init]--;
		}

		s[idx[i]].pop_back();

		if(found) ans[i] = true;
	}

	for(int i = 0; i <= k; i++)
		cout << (ans[i] ? "Yes\n" : "No\n");
	
    return 0;
}


