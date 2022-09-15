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

const int maxn = 100;

int n; 
ll a[maxn], h;

bool ok(ll k) {
	ll ans = 0;
	for(int i = 0; i < n-1; i++) {
		ll damage = min(k, a[i+1]-a[i]);
		ans += damage;
		if(ans >= (ll) 1e18) return 1;
	}
	return (ans+k) >= h;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while(t--) {
		cin >> n >> h;
		for(int i = 0; i < n; i++)
			cin >> a[i];

		ll l = 0, r = (ll) 1e18;
		while(l < r) {
			ll m = (l+r)>>1;
			if(ok(m)) r = m;
			else l = m+1;
		}

		cout << l << "\n";
	}
	
	
	return 0;
}
