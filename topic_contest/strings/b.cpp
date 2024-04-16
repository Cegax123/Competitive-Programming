#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 200;
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

int id[maxn];
int cnt[maxn];

int main() {
    int t; cin >> t;
    while(t--) {
        int k; cin >> k;
		if(k == 1) {
			string s; cin >> s;
			cout << s.size() << "\n";
			continue;
		}
        vector<int> s;
        int pos = 0;
        for(int i = 0; i < k; i++) {
            string p; cin >> p;
            for(int j = 0; j < (int) p.size(); j++) {
                id[pos++] = i;
                s.push_back(p[j]);
            }
            id[pos++] = -1;
            s.push_back(-i);
        }

        vector<int> a = suffix_array(s), lcp = lcp_array(s, a);
        vector<int> apos(a.size());
        for(int i = 0; i < (int) a.size(); i++) apos[a[i]] = i;
		LCP_build(lcp);

		for(int i = 0; i < k; i++) cnt[i] = 0;

		int curr = 0;
		int ind = 0;
		int ans = 0;

		for(int i = 0; i < pos; i++) {
			while(ind < pos and curr != k) {
				if(id[a[ind]] == -1) {
					ind++;
					continue;
				}

				if(cnt[id[a[ind]]] == 0) curr++;
				cnt[id[a[ind]]]++;
				ind++;
			}

			if(curr == k) ans = max(ans, LCP(i, ind-1));

			if(id[a[i]] != -1) {
				cnt[id[a[i]]]--;
				if(cnt[id[a[i]]] == 0) curr--;
			}
		}

		cout << ans << "\n";
    }


    return 0;
}
