#include<bits/stdc++.h>
using namespace std;

const int maxn = 105;
int a[maxn][maxn];

int main() {
	for(int i = 0; i < maxn; i++)
		a[i][0] = a[0][i] = a[i][i] = 400;

	for(int i = 1; i < maxn; i++) {
		for(int j = 1; j < maxn; j++) {
			if(i == j) continue;
			vector<int> cnt(4 * maxn, 0);

			for(int k = 0; k < i; k++) cnt[a[k][j]] = 1;
			for(int k = 0; k < j; k++) cnt[a[i][k]] = 1;

			for(int k = 1; k <= min(i, j); k++)
				cnt[a[i-k][j-k]] = 1;

			for(int k = 0; k < 4 * maxn; k++)
				if(cnt[k] == 0) {
					a[i][j] = k;
					break;
				}

		}
	}

	int n; cin >> n;
	int x = 0;
	for(int i = 0; i < n; i++) {
		int l, c; cin >> l >> c;
		if(l == c) {
			cout << "Y\n";
			return 0;
		}
		x ^= a[l][c];
	}

	cout << (x == 0 ? "N\n" : "Y\n");

	return 0;
}
