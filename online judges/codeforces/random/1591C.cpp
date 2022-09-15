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

ll solve(const vector<ll>& a, int k, bool back) {
	ll ans = 0;
	int n = a.size();
	int r = n-1;

	while(r >= 0) {
		ans += (ll) 2 * a[r];
		r -= k;
	}

	if(!back) ans -= a[n-1];
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while(t--) {
		int n, k; cin >> n >> k;
		vector<ll> a, b;

		for(int i = 0; i < n; i++) {
			int x; cin >> x;
			if(x < 0) a.pb(-x);
			if(x > 0) b.pb(x);
		}

		sort(all(a));
		sort(all(b));

		if(a.empty() and b.empty()) {
			cout << 0 << "\n";
			continue;
		}
		if(a.empty()) cout << solve(b, k, 0) << "\n";
		else if(b.empty()) cout << solve(a, k, 0) << "\n";
		else cout << min(solve(a, k, 1)+solve(b, k, 0), solve(a, k, 0)+solve(b, k, 1)) << "\n";
	}
	
	
	return 0;
}
