#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = (ll) 1e18;

int main() {
	int n, m;
	while(cin >> n and n) {
        cin >> m;

		vector<int> p(m);
		for(int i = 0; i < m; i++) cin >> p[i];

		p.push_back(n);
		p.push_back(0);

		sort(p.begin(), p.end());

		m = p.size();

		vector<vector<ll>> dp(m, vector<ll>(m));
		vector<vector<int>> opt(m, vector<int>(m));

		for(int len = 1; len <= m; len++) {
			for(int i = 0; i + len - 1 < m; i++) {
				int j = i + len - 1;

				if(len <= 2) {
					dp[i][j] = 0;
					opt[i][j] = i;
					continue;
				}

				dp[i][j] = INF;

				for(int k = opt[i][j-1]; k <= opt[i+1][j]; k++) {
					ll sum = dp[i][k] + dp[k][j];
					if(sum < dp[i][j]) {
						dp[i][j] = sum;
						opt[i][j] = k;
					}
				}

				dp[i][j] += p[j] - p[i];
			}
		}

		cout << "The minimum cutting is ";
		cout << dp[0][m-1] << ".\n";
	}


	return 0;
}
