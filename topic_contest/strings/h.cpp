#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
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


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> s(n);

    for(int i = 0; i < n; i++) cin >> s[i];

	vector<int> d = s;
	sort(d.begin(), d.end());
	d.erase(unique(d.begin(), d.end()), d.end());

	for(int i = 0; i < n; i++)
		s[i] = lower_bound(d.begin(), d.end(), s[i])-d.begin();

    s.push_back(-1);

	vector<int> spos[n];
	for(int i = 0; i < n; i++) {
		spos[s[i]].push_back(i);
	}

    vector<int> a = suffix_array(s), lcp = lcp_array(s, a);
    vector<int> pos(a.size());

    for(int i = 0; i <= n; i++)
        pos[a[i]] = i;

    LCP_build(lcp);


    vector<int> rep[n];

	for(int i = 0; i < n; i++) {
		for(int p : spos[s[i]]) {
			if(p <= i) continue;
			int len = p - i;
			if(LCP(pos[i], pos[p]) >= len) {
				rep[len].push_back(i);
				break;
			}
		}
	}

	int ind = 0;

    for(int i = 0; i < n; i++) {
		for(int p : rep[i]) {
			if(p < ind) continue;
			ind = p + i;
		}
    }

	cout << n-ind << "\n";
	for(int i = ind; i < n; i++) cout << d[s[i]] << " ";

    return 0;
}
