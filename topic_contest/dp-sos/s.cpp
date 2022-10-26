// SOLVED

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

const int m = 17;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	
	ll h[1 << m];
	memset(h, 0, sizeof(h));
	
	for(int i = 0; i < n; i++) 
		cin >> h[i];
	
	ll dp[1 << m];
	int q; cin >> q;
	
	int ans[q];
	memset(ans, 0, sizeof(ans));
	
	for(int i = 0; i < q; i += (1 << 9)) {
		vii Q;
		
		memset(dp, 0, sizeof(dp));
		for(int j = i; j < min(q, i+(1 << 9)); j++) {
			int x, y; cin >> x >> y;
			
			for(int k = 17; k < 30; k++) 
				if((x>>k)&1) x ^= (1 << k);
			
			dp[x] = min(dp[x]+y, (ll) 1e10);
			Q.pb({x, y});
		}
		
		for(int j = 0; j < m; j++) {
			for(int mask = 0; mask < (1 << m); mask++) {
				if(((mask >> j)&1)==0) dp[mask] = min(dp[mask]+dp[mask|(1<<j)], (ll) 1e10);
			}
		}
		
		
		vi del;
		for(int j = 0; j < n; j++) 
			if(h[j] and h[j] <= dp[j]) del.pb(j);
			
		for(auto num : del) {
			ll sum = 0;
			for(int j = i; j < min(q, i+(1<<9)); j++) {
				int x = Q[j-i].first; ll y = Q[j-i].second;
				if((num&x) == num) {
					sum = sum + y;
					if(sum >= h[num]) {
						ans[j]++;
						break;
					}
				}		
			}	
		}
		
		for(int j = 0; j < (1 << m); j++) 
			h[j] = max(h[j]-dp[j], 0ll);
	}
	
	for(int i = 1; i < q; i++)
		ans[i] += ans[i-1];
	
	for(int i = 0; i < q; i++)
		cout << n-ans[i] << "\n";
	
	return 0;
}

