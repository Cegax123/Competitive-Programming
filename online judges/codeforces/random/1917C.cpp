#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn], v[maxn];

int main() {
	int t; cin >> t;
	while(t--) {
		int n, k, d; cin >> n >> k >> d;

		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			if(a[i] == i) cnt++;
		}

		for(int i = 0; i < k; i++) cin >> v[i];

		int ans = 0;
		for(int i = 0; i <= min(2 * n+5, d-1); i++) {
			ans = max(ans, cnt + (d-1-i) / 2);

			int x = i%k;
			cnt = 0;

			for(int j = 1; j <= v[x]; j++) {
				a[j]++;
			}

			for(int j = 1; j <= n; j++)
				if(a[j] == j) cnt++;
		}

		cout << ans << "\n";
	}


	return 0;
}
