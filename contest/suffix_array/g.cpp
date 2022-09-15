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
 
vi p, lcp;
 
const int maxn = 4e5+5;
const int LOGN = 20;
 
int ST[maxn][LOGN];
 
int f(int a, int b) {return min(a,b);}
 
void STBuild(const vi& lcp) {
    for(int i = 1; i <= (int) lcp.size(); i++) 
        ST[i][0] = lcp[i-1];
 
    for(int k = 1; (1 << k) <= (int) lcp.size(); k++) {
        int dis = 1 << (k-1);
 
        for(int i = 1; i + 2*dis -1 <= (int) lcp.size(); i++)
            ST[i][k] = f(ST[i][k-1], ST[i+dis][k-1]);
    }
}
 
int STQuery(int L, int R) {
    L++; R++;
 
    int d = R-L+1;
    int k = 31- __builtin_clz(d);
    int dis = 1 << k;
 
    return f(ST[L][k], ST[R-dis+1][k]);
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
	vector<int> lcp(n - 1);
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
    vi vs;
 
    ll n = s.size();
 
    for(char c : s)
    	vs.pb(c-'a'+1);
 
    vs.pb(0);
 
	p = suffix_array(vs), lcp = lcp_array(vs, p);
    lcp.pb(0);
 
    STBuild(lcp);
 
	vector<set<int> > banned(n+1);
	ll ans = (ll) n * (n+1) / 2;
 
	for(int i = 0; i <= n; i++) {
		if(lcp[i] == 0) continue;
 
		// lcp[i] : len(current substring)
		// p[i] : index substring
 
		int l = 0, r = i;
 
		while(l < r) {
			int m = (l+r+1) >> 1;
 
			if(STQuery(m, i) < lcp[i]) l = m;
			else r = m-1;
		}
 
		int L = l;
 
		if(banned[L+1].count(lcp[i])) continue;
 
		banned[L+1].insert(lcp[i]);
 
		l = i, r = n;
 
		while(l < r) {
			int m = (l+r) >> 1;
 
			if(STQuery(i, m) < lcp[i]) r = m;
			else l = m+1;
		}
 
		int R = l;
 
		ll cnt = R-L; // number of current substring
		int dele = max(lcp[L], lcp[R]); // repeated substrings in current substring
 
		ll add = (ll) cnt * (cnt-1ll) / 2ll;
		add *= (ll) lcp[i]-dele;
 
		ans += add;
	}
 
	cout << ans << "\n";
	
    return 0;
}

