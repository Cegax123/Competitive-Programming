#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		string b[n+5];

		for(int i = 0; i < n; i++)
			cin >> b[i];

		int T = 0;

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++)
				if(b[i][j] == '1') T++;
		}

		int global = n * n;

		for(int i = 0; i < n; i++) {
			int x = i, y = 0;
			int diag = 0;

			for(int j = 0; j < n; j++) {
				if(b[x][y] == '1') diag++;
				x++; y++;
				x %= n; y %= n;
			}

			global = min(global, n-diag + (T-diag));
		}

		cout << global << "\n";
	}


	return 0;
}