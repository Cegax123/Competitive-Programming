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

int n, m;
string s;

const int maxn = 4e5;
const int LOGN = 20;

int r[maxn];
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

bool possible(int k) {
	if(k == 0) return 1;

	vector<bool> poss(2 * n, false);

	for(int i = 0; i < 2 * n; i++) {
		if(r[i] >= k) {
			int j = i-min(r[i], k)+1;
			int until = n-min(r[i], k)+1;

			while(j >= 0 and until > 0) {
				if(poss[j]) break;
				poss[j] = 1;
				until--;
				j--;
			}
		}
	}

	//for(int i = 0; i < n; i++) {
		//cout << poss[i] << " ";
	//}
	//cout << endl;

	for(int i = 0; i < n; i++) if(poss[i] == 0) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    cin >> s;

    reverse(all(s));

    vi vs, id;

    for(char c : s) {
        vs.pb(c);
        id.pb(0);
    }

    for(char c : s) {
        vs.pb(c);
        id.pb(0);
    }

    vs.pb(0);
    id.pb(-1);

    for(int i = 1; i <= m; i++) {
        string t; cin >> t;
        reverse(all(t));

        for(char c : t) {
            vs.pb(c);
            id.pb(i);
        }

        vs.pb(-i);
        id.pb(-1);
    }

    vi a = suffix_array(vs), lcp = lcp_array(vs, a);

    LCP_build(lcp);
    int prev[maxn], nxt[maxn];

    prev[0] = -1;

    for(int i = 1; i < (int) a.size(); i++) {
        prev[i] = prev[i-1];
        if(id[a[i]] > 0) prev[i] = i;
    }

    nxt[a.size()-1] = a.size();

    for(int i = a.size()-2 ; i >= 0; i--) {
        nxt[i] = nxt[i+1];
        if(id[a[i]] > 0) nxt[i] = i;
    }

    for(int i = 0; i < (int) a.size(); i++) {
        if(id[a[i]] != 0) continue;

        int curr = 0;

        assert(prev[i] < i);
        assert(nxt[i] >  i);

        if(prev[i] > 0) curr = max(curr, min(n, LCP(prev[i], i)));
        if(nxt[i] > 0) curr = max(curr, min(n, LCP(i, nxt[i])));

        r[2 * n - 1 - a[i]] = curr;
    }

	//for(int i = 0; i < 2 * n; i++)
		//cout << r[i] << " ";

	//cout << endl;

	//cout << possible(2) << endl;

	int lo = 0, ro = n;

	while(lo < ro) {
		int tm = (lo+ro+1) >> 1;
		if(possible(tm)) lo = tm;
		else ro = tm-1;
	}

	cout << lo << endl;

    return 0;
}


