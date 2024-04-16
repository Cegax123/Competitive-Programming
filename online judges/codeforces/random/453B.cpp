#include<bits/stdc++.h>
using namespace std;


int main() {
	vector<int> primes;
	for(int i = 2; i < 60; i++) {
		bool cmp = 1;
		for(int j = 2; j * j <= i; j++) {
			if(i % j == 0) cmp = 0;
		}
		if(cmp) primes.push_back(i);
	}

	int k = primes.size();
	vector<int> mask(60, 0);

	for(int i = 2; i < 60; i++) {
		for(int j = 0; j < k; j++) {
			if(i % primes[j] == 0) mask[i] ^= (1 << j);
		}
	}


	int n; cin >> n;
	int a[n+1];
	for(int i = 1; i <= n; i++) cin >> a[i];

	const int INF = 1e9;
	vector<vector<int>> dp(n+1, vector<int>(1 << k, INF));
	vector<vector<int>> p(n+1, vector<int>(1 << k, -1));
	dp[0][0] = 0;

	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < (1 << k); j++) {
			for(int num = 1; num < 60; num++) {
				if((j&mask[num]) == mask[num]) {
					int curr = dp[i-1][j^mask[num]] + abs(a[i]-num);

					if(curr < dp[i][j]) {
						dp[i][j] = curr;
						p[i][j] = num;
					}
				}
			}
		}
	}

	int ans = INF;
	int mset = -1;
	for(int j = 0; j < (1 << k); j++) {
		if(dp[n][j] < ans) {
			ans = dp[n][j];
			mset = j;
		}
	}

	vector<int> res;

	int ind = n;
	while(ind) {
		int x = p[ind][mset];
		res.push_back(x);
		ind--;
		mset ^= mask[x];
	}

	reverse(res.begin(), res.end());

	for(int x : res) cout << x << " ";
	cout << "\n";

	return 0;
}
