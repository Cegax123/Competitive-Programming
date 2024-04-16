#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int maxn = 1e4;

int ex(int a, int b, int c) {
	int ans = 1;
	while(b) {
		if(b&1) ans = ans * 1ll * a % c;
		a = a * 1ll * a % c;
		b >>= 1;
	}

	return ans;
}

int main() {
	int f[maxn];

	f[0] = 1;
	for(int i = 1; i < maxn; i++) {
		f[i] = i * 1ll * f[i-1] % mod;
	}

	int ivf[maxn];

	ivf[maxn-1] = ex(f[maxn-1], mod-2, mod);
	for(int i = maxn-2; i >= 0; i--) {
		ivf[i] = (i+1) * 1ll * ivf[i+1] % mod;
	}

	int p2[maxn];
	p2[0] = 1;

	for(int i = 1; i < maxn; i++) {
		p2[i] = p2[i-1] * 2ll % mod;
	}

	auto comb = [&](int n, int k) {
		if(k < 0 or n < k) return 0ll;
		return f[n] * 1ll * ivf[k] % mod * ivf[n-k] % mod;
	};

	int k, n; cin >> k >> n;
	
	for(int x = 2; x <= 2 * k; x++) {
		int cnt = 0;
		bool doub = 0;

		for(int i = 1; i <= k; i++) {
			int j = x - i;
			if(j >= 1 and j <= k and i <= j) {
				if(i == j) doub = 1;
				else cnt++;
			}
		}

		int ans = 0;

		for(int t = 0; t <= cnt; t++) {
			int target = n - t;
			int num = k - 2 * cnt - doub + t;

			ans = (ans + p2[t] * 1ll * comb(target + num - 1, num - 1) % mod * comb(cnt, t) % mod) % mod;

			if(doub) {
				target--;
				ans = (ans + p2[t] * 1ll * comb(target + num - 1, num - 1) % mod * comb(cnt, t)) % mod;
			}

		}
		
		cout << ans << "\n";
	}

	return 0;
}

