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

const int maxa = 1e6+5;

bool sieve[maxa];

void fill_sieve() {
	memset(sieve, 0, sizeof(sieve));
	sieve[0] = sieve[1] = 1;

	for(int i = 2; i < maxa; i++) {
		if(sieve[i]) continue;
		for(int j = 2; i * j < maxa; j++) {
			sieve[i*j] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fill_sieve();

	int t; cin >> t;
	while(t--) {
		int n, e; cin >> n >> e;
		int a[n];

		for(int i = 0; i < n; i++) 
			cin >> a[i];

		ll ans = 0;
		for(int i = 0; i < e; i++) {
			for(int j = i; j < n; j += e) {
				if(sieve[a[j]] == 0) {
					ll l = 1, r = 1;
					while(j + e*r < n and a[j + e*r] == 1)
						r++;
					while(j - e*l >= 0 and a[j - e*l] == 1)
						l++;
					l--; r--;

					if(l == 0 or r == 0) ans += l+r;
					else ans += (ll) (l+1) * (r+1) - 1;


				}
			}
		}

		cout << ans << "\n";
	}
	
	
	return 0;
}
