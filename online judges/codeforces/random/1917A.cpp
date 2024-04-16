#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		int a[n];

		bool iszero = false;
		int cnt_neg = 0;

		for(int i = 0; i < n; i++) {
			cin >> a[i];
			if(a[i] == 0) iszero = 1;
			else if(a[i] < 0) cnt_neg++;
		}

		if(iszero) {
			cout << 0 << "\n";
		}
		else {
			if(cnt_neg % 2 == 0) {
				cout << 1 << "\n";
				cout << 1 << " " << 0 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
	}


	return 0;
}
