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

const ll mod = 998244353;

ll sum(ll a, ll b, ll c) {
	ll ans = (a+b)%c;
	return (ans+c)%c;
}

ll mul(ll a, ll b, ll c) {
	return a*b%c;
}

ll f(const vector<int>& l, const vector<int>& r, const int& m, const int& n) {
	ll dp[n][m+1];
	ll sumdp[m+1];

	memset(dp, 0, sizeof(dp));

	for(int i = l[0]; i <= r[0]; i++) 
		dp[0][i] = 1;

	for(int i = 0; i <= m; i++) 
		sumdp[i] = (i == 0 ? dp[0][0] : sumdp[i-1] + dp[0][i]);

	for(int i = 1; i < n; i++) {
		for(int j = 0; j <= m; j++) {
			if(j < l[i]) continue;

			int L = max(0, j-r[i]), R = j-l[i];
			dp[i][j] = sum(dp[i][j], sumdp[R]-(L == 0 ? 0 : sumdp[L-1]), mod);
		}

		for(int j = 0; j <= m; j++) {
			if(j == 0) sumdp[j] = dp[i][0];
			else sumdp[j] = sum(sumdp[j-1], dp[i][j], mod);
		}
	}

	return sumdp[m];
}

const int maxm = 1e5;
int sieve[maxm+5];
vi primes;
int mu[maxm+5];

void fill_sieve() {
	sieve[1] = 1;

	for(int i = 2; i <= maxm; i++) {
		if(sieve[i]) continue;

		sieve[i] = i;
		primes.pb(i);

		for(int j = 2; i*j <= maxm; j++) {
			if(sieve[i*j]) continue;
			sieve[i*j] = (sieve[j] == 0 ? i : i * sieve[j]);
		}
	}
}

void fill_mu() {
	mu[1] = 1;
	for(int p : primes)
		mu[p] = -1;

	for(int i = 2; i <= maxm; i++) {
		if(sieve[i] == i) continue;
		mu[i] = mu[sieve[i]] * mu[i/sieve[i]];
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	fill_sieve();
	fill_mu();

	int n, m; cin >> n >> m;
	vi L(n), R(n);

	for(int i = 0; i < n; i++)
		cin >> L[i] >> R[i];

	ll ans = 0;
	for(int d = 1; d <= m; d++) {
		vi l(n), r(n);

		for(int i = 0; i < n; i++) {
			l[i] = (L[i]+d-1)/d;
			r[i] = R[i]/d;
		}

		ans = sum(ans, mul(mu[d], f(l, r, m/d, n), mod), mod);
	}

	cout << ans << "\n";
	
	return 0;
}

