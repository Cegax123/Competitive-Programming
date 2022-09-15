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
	int n, q; cin >> n >> q;
	vi cnt(n, 0);
	vi a(n);

	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	while(q--) {
		int l, r; cin >> l >> r;
		l--; r--;
		cnt[l]++;
		if(r+1 < n) cnt[r+1]--;
	}

	for(int i = 1; i < n; i++)
		cnt[i] += cnt[i-1];

	sort(all(a));
	sort(all(cnt));

	ll ans = 0;

	for(int i = 0; i < n; i++)
		ans += (ll) a[i] * cnt[i];

	cout << ans << "\n";
	return 0;
}
