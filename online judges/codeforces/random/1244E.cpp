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

vi a;
int n;
ll k, Lsum[maxn], Rsum[maxn];

ll L(ll x) {
	if(x <= a[0]) return 0;
		
	int l = 0, r = n-1;
	while(l < r) {
		int m = (l+r+1)>>1;
		if(a[m] < x) l = m;
		else r = m-1;
	}

	return (ll) Lsum[l] - (l+1ll) * (1e9L-x);
}

ll R(ll x) {
	if(x >= a[n-1]) return 0;

	int l = 0, r = n-1;
	while(l < r) {
		int m = (l+r)>>1;
		if(a[m] > x) r = m;
		else l = m+1;
	}

	return (ll) Rsum[l] - ((ll)n-l) * ((ll)x);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	a.resize(n);

	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(all(a));

	for(int i = 0; i < n; i++) {
		Lsum[i] = 1e9-a[i];
		Rsum[i] = a[i];
	}
		
	for(int i = 1; i < n; i++) Lsum[i] += Lsum[i-1];
	for(int i = n-2; i >= 0; i--) Rsum[i] += Rsum[i+1];


	int ans = a[n-1]-a[0];

	for(int i = 0; i < n; i++) {
		ll Li = L(a[i]);

		int l = a[i], r = 1e9;
		while(l < r) {
			int m = (l+r)/2;

			if(R(m) + Li <= k) r = m;
			else l = m+1;
		}

		if(R(l) + Li <= k) {
		    ans = min(ans, l-a[i]);
		}
	}

	for(int i = 0; i < n; i++) {
		ll Ri = R(a[i]);

		int l = 0, r = a[i];
		while(l < r) {
						int m = (l+r+1)/2;

						if(L(m) + Ri <= k) l = m;
						else r = m-1;
				}

				if(L(l) + Ri <= k) {
						ans = min(ans, a[i]-l);
				}
		}


		cout << ans << "\n";

		return 0;
}

