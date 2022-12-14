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

const int maxn = 5e5+5;
const int LOGN = 20;

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
    string s; cin >> s;

    vi vs;
    for(char c : s) vs.pb(c);
    vs.pb(0);

	vi a = suffix_array(vs), lcp = lcp_array(vs, a);

	int R[n+1][LOGN];

	vi tmp;

	for(int i = 0; i <= n; i++)
		R[i][0] = i;

	for(int i = 0; i < n; i++) {
		if(s[i] == '(') tmp.pb(i);
		else {
			if(!tmp.empty()) {
				R[tmp.back()][0] = i+1;
				tmp.pop_back();
			}
		}
	}

	int cnt[n+1];
	memset(cnt, 0, sizeof(cnt));

	for(int i = n; i >= 0; i--) {
		cnt[i] = (R[i][0] > i) + cnt[R[i][0]];

		for(int j = 1; j < LOGN; j++) {
			R[i][j] = R[R[i][j-1]][j-1];
		}
	}

	auto get_len = [&] (int pos, int num) {
		int st = pos;
		for(int i = 0; i < LOGN; i++) {
			if((num >> i)&1) {
				pos = R[pos][i];
			}
		}
		return pos-st;
	};

	//for(int i = 0; i < (int) a.size(); i++) {
		//cout << a[i] << " " << s.substr(a[i], n-a[i]) << "\n";
	//}

	ll ans = 0;

	for(int i = 1; i < (int) a.size(); i++) {
		int rep = lcp[i-1];
		if(get_len(a[i], cnt[a[i]]) <= rep) continue;

		int l = 1, r = cnt[a[i]];

		while(l < r) {
			int m = (l+r) >> 1;
			if(get_len(a[i], m) > rep) r = m;
			else l = m+1;
		}

		ans += cnt[a[i]]-l+1;
	}

	cout << ans << "\n";

    return 0;
}


