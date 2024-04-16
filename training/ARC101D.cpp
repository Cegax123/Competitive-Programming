#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int a[n];
	vector<int> s;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		s.push_back(a[i]);
	}

	map<int, int> cnt;

	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			vector<int> v;
			for(int k = i; k <= j; k++) v.push_back(a[k]);
			sort(v.begin(), v.end());
			
			int len = j-i+1;
			cnt[v[len/2]]++;
		}
	}

	for(auto e : cnt) {
		cout << e.first << " " << e.second << "\n";
	}

	map<int, int> cnt2;
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());

	for(int x : s) {
		vector<int> v(n, -1);

		for(int i = 0; i < n; i++) if(a[i] >= x) v[i] = 1;

		for(int i = 0; i < n; i++) {
			for(int j = i; j < n; j++) {
				int sum = 0;
				for(int k = i; k <= j; k++)
					sum += v[k];

				if(sum >= 0) cnt2[x]++;
			}
		}
	}

	cout << endl;
	for(auto e : cnt2) {
		cout << e.first << " " << e.second << "\n";
	}

	return 0;
}
