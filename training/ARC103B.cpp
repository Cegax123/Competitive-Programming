#include<bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	int n = s.size();

	s = "0" + s;

	if(s[1] == '0') {
		cout << -1 << "\n";
		return 0;
	}
	
	for(int i = 0; i <= n; i++) {
		if(s[i] != s[n-i]) {
			cout << -1 << "\n";
			return 0;
		}
	}

	vector<int> needed;

	for(int i = 2; i <= n/2; i++)
		if(s[i] == '1') needed.push_back(i);

	needed.push_back(n);

	int ind = 1;
	int bp = 1;
	int curr = 1;

	vector<pair<int, int>> edges;

	for(int x : needed) {
		int k = x - ind - 1;
		int p = ++ind;

		cout << bp << " " << p << "\n";

		for(int i = 0; i < k; i++) 
			cout << p << " " << ++ind << "\n";

		bp = p;
	}

	return 0;
}
