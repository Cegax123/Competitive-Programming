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

const int maxn = 1e7;

int sieve[maxn+5];
vi primes;
ll f[maxn+1];

void fill_sieve() {
	sieve[1] = 1;

	for(int i = 2; i <= maxn; i++) {
		if(sieve[i]) continue;
		sieve[i] = i;

		primes.pb(i);

		for(int j = 2; i*j <= maxn; j++) {
			if(sieve[i*j]) continue;
			sieve[i*j] = (sieve[j] == 0 ? i : i * sieve[j]);
		}
	}
}

ll solve(int n) {
    ll ans = 0;

    for(int i = 1; i <= n; i++) {
        ans += n / __gcd(n, i);
    }
    return ans;
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	fill_sieve();

	f[1] = 1;
	for(ll p : primes) {
		ll tmp = p;
		while(tmp <= maxn) {
			f[tmp] = (ll) (tmp * tmp * p + 1ll) / (p+1ll);
			tmp *= p;
		}
	}

	for(int i = 1; i <= maxn; i++) {
		if(f[i]) continue;
		f[i] = f[sieve[i]] * f[i/sieve[i]] * 1ll;
	}

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		cout << f[n] << "\n";
	}
	
	return 0;
}

