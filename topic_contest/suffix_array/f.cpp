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

vi p, lcp, vs, pos;

const int maxn = 4e5+5;
const int LOGN = 20;

int n;
int ST[maxn][LOGN];

void STBuild() {
    for(int i = 1; i <= n; i++) 
        ST[i][0] = lcp[i-1];

    for(int k = 1; (1 << k) <= n; k++) {
        int dis = 1 << (k-1);

        for(int i = 1; i + 2*dis -1 <= n; i++)
            ST[i][k] = min(ST[i][k-1], ST[i+dis][k-1]);
    }
}

int STQuery(int L, int R) {
    L++; R++;

    int d = R-L+1;
    int k = 31- __builtin_clz(d);
    int dis = 1 << k;

    return min(ST[L][k], ST[R-dis+1][k]);
}

bool comp(const ii& a, const ii& b) {
    int l1 = a.first, l2 = b.first;
    int r1 = a.second, r2 = b.second;
    int len1 = r1-l1+1, len2 = r2-l2+1;

    if(l1 == l2) 
        return r1 < r2;

    int pl1 = pos[l1], pl2 = pos[l2];

    int curr_lcp = STQuery(min(pl1, pl2), max(pl1, pl2)-1);
    
    if(curr_lcp >= max(len1, len2)) 
        return (len1 < len2) or (len1 == len2 and l1 < l2);

    if(len1 > curr_lcp and len2 > curr_lcp) 
        return pl1 < pl2;

    return len1 < len2;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
    string s; cin >> s;
    s += ' ';

    for(char c : s)
        vs.pb(c);

    n = s.size();

    p = suffix_array(vs);

    pos.resize(n);

    for(int i = 0; i < n; i++)
        pos[p[i]] = i;

    lcp = lcp_array(vs, p);

    n--;

    STBuild();

    int q; cin >> q;
    vii inter;

    for(int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        l--; r--;

        inter.pb({l, r});
    }

    sort(all(inter), comp);

    for(int i = 0; i < q; i++) {
        cout << inter[i].first+1 << " " << inter[i].second+1 << "\n";
    }
	
	return 0;
}

