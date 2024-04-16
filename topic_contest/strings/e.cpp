#include<bits/stdc++.h>
using namespace std;

const int maxn = 5005;
const int mod = 1e9 + 7;
int dp[maxn][maxn];
int sdp[maxn][maxn];

int n;
string s;
vector<int> a, lcp;
vector<int> pos;

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


bool is_bigger(int i, int j, int a, int b) {
    int len = j-i+1;
    int common_len = LCP(pos[i], pos[a]);

    if(common_len >= len) return false;

    return s[i+common_len] > s[a+common_len];
}

int main() {
    cin >> n >> s;

    vector<int> vs;
    for(char c : s) vs.push_back(c);
	vs.push_back(0);

    a = suffix_array(vs), lcp = lcp_array(vs, a);

    LCP_build(lcp);
    pos.resize(a.size());

    for(int i = 0; i < (int) a.size(); i++) {
        pos[a[i]] = i;
    }

    dp[1][1] = 1;
    sdp[1][0] = dp[1][0];
    for(int i = 1; i <= n; i++) {
        sdp[1][i] = (dp[1][i] + sdp[1][i-1]) % mod;
    }

    for(int i = 2; i <= n; i++) {
        dp[i][i] = 1;

        for(int j = 1; j < i; j++) {
			if(s[i-j] == '0') {
				dp[i][j] = 0;
				continue;
			}
			
            dp[i][j] = sdp[i-j][j-1];

            if(i-2*j >= 0 and is_bigger(i-j, i-1, i-2*j, i-j-1)) 
                dp[i][j] = (dp[i][j] + dp[i-j][j]) % mod;
        }

        sdp[i][0] = dp[i][0];
        for(int j = 1; j <= n; j++) {
            sdp[i][j] = (dp[i][j] + sdp[i][j-1]) % mod;
        }
    }

    cout << sdp[n][n] << "\n";

    return 0;
}


