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
const int maxa = 5e6+5;

int n;
vi a;

int cnt[maxa];
int sieve[maxa];
ll dp[maxa];

int p[maxa][12];
int curr[maxa];

void init() {
	sieve[0] = sieve[1] = 1;

	for(int i = 2; i < (int) maxa; i++) {
		if(sieve[i]) continue;
		
		sieve[i] = i;
		p[i][curr[i]++] = i;

		for(int j = 2; i * j < (int) maxa; j++) {
			if(sieve[i*j] == 0) sieve[i*j] = i;
			p[i*j][curr[i*j]++] = i;
		}
	}
}

void add(int x) {
	vi tmp(1, 1);
	cnt[1]++;

	while(x != 1) {
		int d = sieve[x];
		int cntd = 0;

		while(x % d == 0) {
			x /= d;
			cntd++;
		}

		int pd = d;
		int k = tmp.size();
		for(int i = 0; i < cntd; i++) {
			for(int j = 0; j < k; j++) {
				cnt[tmp[j] * pd]++;
				tmp.pb(tmp[j] * pd);
			}
			pd *= d;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	init();

	cin >> n;

	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		a.pb(x);
	} 
	
	sort(all(a));
	reverse(all(a));

	for(int i = 0; i < n; i++) {
		add(a[i]);
	}

	for(int i = 1; i < maxa; i++) {
		dp[i] = (ll) cnt[i] * i;
	}

	for(int j = maxa-1; j >= 2; j--) {
		for(int k = 0; k < curr[j]; k++) {
			int divp = p[j][k];
			int i = j / divp;
			dp[i] = max(dp[i], (ll) dp[j] + i * (cnt[i]-cnt[j]));
		}
	}

	cout << dp[1] << "\n";

	return 0;
}
