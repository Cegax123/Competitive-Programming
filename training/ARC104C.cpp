#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int l[2 * n + 1], r[2 * n + 1];

	memset(l, 0, sizeof(l));
	memset(r, 0, sizeof(r));

	int cnt = 0;
	for(int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;

		if(a == -1 and b == -1) cnt++;

		if(a != -1) l[a] = b;
		if(b != -1) r[b] = a;
	}

	int dp[2 * n + 1][2 * n + 1];

	memset(dp, -1, sizeof(dp));

	dp[0][0] = 0;

	for(int i = 1; i < 2 * n; i++) {
		for(int j = i+1; j <= 2 * n; j += 2) {
			bool cmp = true;
			int need = 0;
			int len = j-i+1;
			len /= 2;
			for(int k = i; k < i+len; k++) {
				int o = k + len;


				if(l[k] == 0 and r[o] == 0) {
					need++;
				}
				else if(l[k] == 0) {
					if(r[o] != -1 and r[o] != k) cmp = false;
				}
				else if(r[o] == 0) {
					if(l[k] != -1 and l[k] != o) cmp = false;
				}
				else {
					if(l[k] == -1 and r[o] == -1) cmp = false;
					else {
						if(!(l[k] == o and r[o] == k)) cmp = false;
					}
				}
			}

			if(cmp) dp[i][j] = need;
			
		}
	}

	int build[2 * n + 1];
	memset(build, -1, sizeof(build));

	build[0] = 0;

	for(int i = 2; i <= 2 * n; i += 2) {
		for(int j = i-2; j >= 0; j -= 2) {
			if(dp[j+1][i] == -1 or build[j] == -1) continue;
			int tot = dp[j+1][i] + build[j];

			if(build[i] == -1) build[i] = tot;
			else build[i] = min(build[i], tot);
		}
	}

	if(build[2 * n] != -1 and build[2 * n] <= cnt) cout << "Yes\n";
	else cout << "No\n";

	return 0;
}
