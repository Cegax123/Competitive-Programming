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



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	vector<ll> a(n);

	for(int i = 0; i < n; i++)
		cin >> a[i];

	ll ans = 0;

	for(ll i : a)
		for(ll j : a)
			for(ll k : a)
				ans = max(ans, i|j|k);

	cout << ans << "\n";
	
	return 0;
}