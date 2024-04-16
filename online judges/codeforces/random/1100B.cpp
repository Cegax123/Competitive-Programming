#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<int> cnt(n+1, 0);
	int curr = 0;

	for(int i = 0; i < m; i++) {
		int a; cin >> a;
		if(cnt[a] == 0) curr++;
		cnt[a]++;

		cout << (curr == n);

		if(curr == n) {
			for(int j = 1; j <= n; j++) {
				cnt[j]--;
				if(cnt[j] == 0) curr--;
			}
		}
	}

	return 0;
}
