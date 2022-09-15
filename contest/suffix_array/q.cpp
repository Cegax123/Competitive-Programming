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
const int maxn = 4e5+5;
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

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s; cin >> s;
    n = s.size() + 1;

    int q; cin >> q;
    string t[q];

    for(int i = 0; i < q; i++) {
        cin >> t[i];
        n += t[i].size() + 1;
    }

	vi v(n, 0);
	for(int i = 0; i < (int) s.size(); i++) v[i] = s[i];
    
    vi suf[q];
	int ind = s.size() + 1;
	for(int i = 0; i < q; i++) {
		for(int j = 0; j < (int) t[i].size(); j++) {
			v[ind + j] = t[i][j];
			suf[i].pb(ind + j);
		}
		ind += t[i].size() + 1;
	}

	vi a = suffix_array(v), lcp = lcp_array(v, a);
	LCP_build(lcp);

	vi pos(n, 0);

	for(int i = 0; i < n; i++)
		pos[a[i]] = i;

	vi prev(n, -1), nxt(n, n);

	if(a[0] < (int) s.size()) prev[0] = 0;
	
	for(int i = 1; i < n; i++) {
		prev[i] = prev[i-1];
		if(a[i] < (int) s.size()) prev[i] = i;
	}

	if(a[n-1] < (int) s.size()) nxt[n-1] = n-1;

	for(int i = n-2; i >= 0; i--) {
		nxt[i] = nxt[i+1];
		if(a[i] < (int) s.size()) nxt[i] = i;
	}


	for(int i = 0; i < q; i++) {
		int ind = 0, ans = 0;

		while(ind < (int) t[i].size()) {
			int p = pos[suf[i][ind]];
			int mx_len = 0;

			// cout << p << " " << nxt[p] << " " << prev[p] << endl;

			if(nxt[p] < n and p < nxt[p])
				mx_len = max(mx_len, LCP(p, nxt[p]));
			if(prev[p] >= 0 and p > prev[p])
				mx_len = max(mx_len, LCP(prev[p], p));

			if(mx_len == 0) {
				ans = -1;
				break;
			}

			ans++;
			ind += mx_len;
		}

		cout << ans << "\n";
	}
   
    return 0;
}


