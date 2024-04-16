#include<bits/stdc++.h>
using namespace std;

const int maxn = 105;
double p[maxn];
double sp[maxn];
double dp[maxn][maxn];
int opt[maxn][maxn];

string s;
vector<string> ans;

void dfs(int i, int j) {
	if(i == j) {
		ans.push_back(s);
		return;
	}


	int k = opt[i][j];

	s += "0";
	dfs(i, k);

	s.pop_back();
	s += "1";
	dfs(k+1, j);

	s.pop_back();
}

int main() {
	bool first = true;
	int n;

	while(cin >> n and n) {
		if(!first) cout << "\n";
		first = false;
		for(int i = 0; i < n; i++) cin >> p[i];

		sp[0] = p[0];
		for(int i = 1; i < n; i++) sp[i] = sp[i-1] + p[i];

		for(int len = 1; len <= n; len++) {
			for(int i = 0; i + len - 1 < n; i++) {
				int j = i + len - 1;

				if(i == j) {
					dp[i][j] = 0.0;
					opt[i][j] = i;
					continue;
				}

				dp[i][j] = 1e9;

				for(int k = opt[i][j-1]; k <= opt[i+1][j]; k++) {
					double curr = dp[i][k] + dp[k+1][j];
					if(curr < dp[i][j]) {
						dp[i][j] = curr;
						opt[i][j] = k;
					}
				}

				dp[i][j] += sp[j] - (i == 0 ? 0.0 : sp[i-1]);
			}
		}

		ans.clear();
		dfs(0, n-1);

		cout << setprecision(4) << fixed;
		cout << dp[0][n-1] << "\n";

		for(string s : ans) cout << s << "\n";
	}


	return 0;
}
