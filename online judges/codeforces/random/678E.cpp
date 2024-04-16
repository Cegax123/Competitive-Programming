#include<bits/stdc++.h>
using namespace std;

const int maxn = 18;
double a[maxn][maxn];
double dp[maxn][1 << maxn];

int main() {
	int n; cin >> n;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) cin >> a[i][j];

	for(int mask = 1; mask < (1 << n); mask++) {
		vector<int> el;
		for(int j = 0; j < n; j++) {
			if((mask>>j)&1) el.push_back(j);
		}

		if((int) el.size() == 1) {
			dp[el[0]][mask] = 1.0;
			continue;
		}

		for(int i : el) {
			for(int j : el) {
				if(i == j) continue;

				dp[i][mask] += dp[j][mask^(1<<i)] * a[i][j];
				//sum2 += dp[i][mask^(1<<j)] * a[i][j];
			}

			for(int j : el) {
				if(i == j) continue;

			}

			//dp[i][mask] = max(sum1, sum2);
		}
	}

	cout << dp[0][(1<<n)-1] << "\n";

	return 0;
}
