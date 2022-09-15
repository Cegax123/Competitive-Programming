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

int n; // tamaño del string sin el empty character
vi p, lcp;

const int maxn = 5e5+5;
const int LOGN = 20;

int LCP[maxn][LOGN];

void LCP_build(const vi& lcp) {
    for(int i = 1; i <= (int) lcp.size(); i++) 
        LCP[i][0] = lcp[i-1];

    for(int k = 1; (1 << k) <= (int) lcp.size(); k++) {
        int dis = 1 << (k-1);

        for(int i = 1; i + 2*dis -1 <= (int) lcp.size(); i++)
            LCP[i][k] = min(LCP[i][k-1], LCP[i+dis][k-1]);
    }
}

int LCP_query(int L, int R) {
    L++; R++;

    int d = R-L+1;
    int k = 31- __builtin_clz(d);
    int dis = 1 << k;

    return min(LCP[L][k], LCP[R-dis+1][k]);
}

int P[maxn][LOGN];

void P_build(const vi& p) {
    for(int i = 1; i <= (int) p.size(); i++) 
        P[i][0] = p[i-1];
    
    for(int k = 1; (1 << k) <= (int) p.size(); k++) {
        int dis = 1 << (k-1);

        for(int i = 1; i + 2*dis -1 <= (int) p.size(); i++)
            P[i][k] = min(P[i][k-1], P[i+dis][k-1]);
    }
}

int P_query(int L, int R) {
    L++; R++;

    int d = R-L+1;
    int k = 31-__builtin_clz(d);
    int dis = 1 << k;

    return min(P[L][k], P[R-dis+1][k]);
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

ll t[4*maxn];

void update(int v, int tl, int tr, int l, int r) {
    if(r < tl or tr < l)
        return;

    if(tl == l and r == tr) {
        t[v]++;
    }
    else {
        int tm = (tl+tr) >> 1;
        update(v*2, tl, tm, l, min(r, tm));
        update(v*2+1, tm+1, tr, max(l, tm+1), r);
    }
}

ll get(int v, int tl, int tr, int pos) {
    if(tl == tr)
        return t[v];

    else {
        int tm = (tl+tr) >> 1;

        if(pos <= tm)
            return t[v] + get(v*2, tl, tm, pos);
        else 
            return t[v] + get(v*2+1, tm+1, tr, pos);
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s; cin >> s;
    n = s.size();

    vi vs;

    for(int i = 0; i < n; i++)
        vs.pb(s[i]-'a'+1);
	
    vs.pb(0);

    p = suffix_array(vs), lcp = lcp_array(vs, p);
    lcp.pb(0);

    LCP_build(lcp);
    P_build(p);

    vector<ll> cnt_subs(n, 0);
	
    for(int i = 1; i <= n; i++) {
		int mx = max(lcp[i], lcp[i-1]);

        if(p[i]+mx <= n-1) update(1, 0, n-1, p[i]+mx, n-1);

        // for(int j = n-p[i]; j > mx; j--) {
        //     cnt_subs[p[i]+j-1]++;
        // }
	}

	vector<set<int> > banned(n+1);

	for(int i = 0; i <= n; i++) {
		if(lcp[i] == 0) continue;

		// lcp[i] : len(current substring)
		// p[i] : index substring

		int l = 0, r = i;

		while(l < r) {
			int m = (l+r+1) >> 1;

			if(LCP_query(m, i) < lcp[i]) l = m;
			else r = m-1;
		}

		int L = l;

		if(banned[L+1].count(lcp[i])) continue;

		banned[L+1].insert(lcp[i]);

		l = i, r = n;

		while(l < r) {
			int m = (l+r) >> 1;

			if(LCP_query(i, m) < lcp[i]) r = m;
			else l = m+1;
		}

		int R = l;

		int dele = max(lcp[L], lcp[R]); // repeated substrings in current substring
        
        int min_p = P_query(L+1, R);

        if(min_p+dele <= min_p+lcp[i]-1) update(1, 0, n-1, min_p+dele, min_p+lcp[i]-1);

        // for(int j = lcp[i]; j > dele; j--)
        //     cnt_subs[min_p+j-1]++;
	}

    for(int i = 0; i < n; i++)
        cnt_subs[i] = get(1, 0, n-1, i);

    for(int i = 1; i < n; i++)
        cnt_subs[i] += cnt_subs[i-1];

    for(int i = 0; i < n; i++) {
        cout << cnt_subs[i] << "\n";
    }

	return 0;
}

