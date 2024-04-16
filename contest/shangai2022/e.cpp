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
const int maxk = 105;

int dp[maxn][maxk];

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
    int t; cin >> t;
    while(t--) {
        string s, f; cin >> s >> f;
        
        int n = s.size(), k = f.size();

        for(int i = 0; i < n; i++)
            for(int j = 0; j < k; j++)
                dp[i][j] = -1;

        auto setVal = [&](int i, int j, int val) {
            if(dp[i][j] == -1) dp[i][j] = val;
            else {
                dp[i][j] = min(dp[i][j], val);
            }
        };

        if(s[n-1] == f[k-1]) dp[n-1][k-1] = n-1;

        for(int i = n-2; i >= 0; i--) {
            for(int j = k-1; j >= 0; j--) {
                if(dp[i+1][j] >= 0) setVal(i, j, dp[i+1][j]);
                if(j == k-1) {
                    if(s[i] == f[j]) {
                        setVal(i, j, i);
                        dp[i][j] = i;
                    }
                }
                else {
                    if(s[i] == f[j] and dp[i+1][j+1] >= 0) {
                        setVal(i, j, dp[i+1][j+1]);
                    }
                }
            }
        }

        int ans = -1;
        int len = n;
        for(int i = 0; i < n; i++) {
            if(dp[i][0] >= 0) {
                int currlen = dp[i][0]-i+1;

                if(currlen <= len) {
                    len = currlen;
                    ans = i;
                }
            }
        }

        for(int y = ans; y <= dp[ans][0]; y++) {
            cout << s[y];
        }
        cout << "\n";
    }

	
    return 0;
}


