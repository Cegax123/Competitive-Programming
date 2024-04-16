#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e4+5;
const int LOGN = 20;

vector<vector<int>> LCP_ST1, LCP_ST2;

void LCP_build(const vector<int>& lcp, vector<vector<int>>& LCP_ST) {
    for(int i = 1; i <= (int) lcp.size(); i++) 
        LCP_ST[i][0] = lcp[i-1];

    for(int k = 1; (1 << k) <= (int) lcp.size(); k++) {
        int dis = 1 << (k-1);

        for(int i = 1; i + 2*dis -1 <= (int) lcp.size(); i++)
            LCP_ST[i][k] = min(LCP_ST[i][k-1], LCP_ST[i+dis][k-1]);
    }
}

int LCP(int L, int R, const vector<vector<int>>& LCP_ST) {
	if(L > R) swap(L, R);
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
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
		int n; cin >> n;
		vector<int> s;

		for(int i = 0; i < n; i++) {
			char c; cin >> c;
			s.push_back(c);
		}

		s.push_back(0);

		vector<int> a = suffix_array(s), lcp = lcp_array(s, a);
		vector<int> pos1(s.size());

		for(int i = 0; i < (int) s.size(); i++) pos1[a[i]] = i;

		LCP_ST1.clear();
		LCP_ST1.resize(n+5, vector<int>(LOGN, 0));

		LCP_build(lcp, LCP_ST1);

		s.pop_back();
		reverse(s.begin(), s.end());
		s.push_back(0);

		a = suffix_array(s), lcp = lcp_array(s, a);
		vector<int> pos2(s.size());

		for(int i = 0; i < (int) s.size(); i++) pos2[a[i]] = i;

		LCP_ST2.clear();
		LCP_ST2.resize(n+5, vector<int>(LOGN, 0));

		LCP_build(lcp, LCP_ST2);
		int global = 1;

		for(int l = 1; l <= n; l++) {
			for(int i = 0; i + l < n; i += l) {
				int t = LCP(pos1[i], pos1[i+l], LCP_ST1);
				int ans = t / l + 1;
				int lft = 0;
				if(i) {
					lft = LCP(pos2[n-1-(i-1)], pos2[n-1-(i+l-1)], LCP_ST2);
				}
				if((t%l) + lft >= l) ans++;

				global = max(global, ans);
			}
		}

		cout << global << "\n";
    }

    return 0;
}
