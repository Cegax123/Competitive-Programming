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

const int maxn = 1e5+5;
const int LOGN = 20;
const int INF = 1e9;

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
    int b; cin >> b;
    string s; cin >> s;
	int n = s.size();

    vi vs;
    for(char c : s)
        vs.pb(c);

    vs.pb(0);

    vi a = suffix_array(vs);
    vi lcp = lcp_array(vs, a);
	LCP_build(lcp);

	vi pos(n+1);
	
	for(int i = 0; i <= n; i++) 
		pos[a[i]] = i;

	int ans = n;

	for(int len = 2; len <= b; len++) {
		//cout << "len: " << len << "\n";

		int ind = 0;

		int id[n];
		memset(id, -1, sizeof(id));

		int curr_id = 0;

		while(ind <= n) {
			if(n-a[ind] < len) {
				ind++;
				continue;
			}

			int L = ind;

			id[a[L]] = curr_id;

			ind++;
			while(ind <= n and LCP(L, ind) >= len) {
				id[a[ind++]] = curr_id;
			}

			curr_id++;
		}

		vi v[curr_id];

		for(int j = 0; j < curr_id; j++)
			v[j].pb(-INF);

		for(int j = 0; j < n; j++)
			if(id[j] != -1) 
				v[id[j]].pb(j);

		//for(int j = 0; j < curr_id; j++) {
			//for(int x : v[j]) cout << x << " ";
			//cout << endl;
		//}

		for(int k = 0; k < curr_id; k++) {
			int dp[v[k].size()];
			memset(dp, 0, sizeof(dp));

			for(int j = 1; j < (int) v[k].size(); j++) {
				dp[j] = dp[j-1];

				int l = 0, r = j-1;
				while(l < r) {
					int m = (l+r+1) >> 1;
					if(v[k][m] + len <= v[k][j]) l = m;
					else r = m-1;
				}

				dp[j] = max(dp[j], dp[l] + 1);

			}

			ans = min(ans, n-dp[v[k].size()-1]*(len-1));
		}

		//for(int i = 0; i < n; i++)
			//cout << id[i] << " ";

		//cout << "\n";
	}

	cout << ans << "\n";
	
    return 0;
}


