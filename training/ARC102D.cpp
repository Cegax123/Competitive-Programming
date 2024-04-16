#include<bits/stdc++.h>
using namespace std;

int main() {
	int l; cin >> l;

	const int L = 20;
	int f = 0;

	for(int i = 0; i < L; i++) {
		if((l >> i)&1) f = i;
	}

	int p2 = 1;

	vector<vector<int>> edges;

	for(int i = 1; i <= f; i++) {
		edges.push_back({i, i+1, 0});
		edges.push_back({i, i+1, p2});
		//cout << i << " " << i+1 << " " << 0 << "\n";
		//cout << i << " " << i+1 << " " << p2 << "\n";
		p2 *= 2;
	}

	int sum = p2;
	for(int i = f-1; i >= 0; i--) {
		if(((l>>i)&1) == 0) continue;

		edges.push_back({i+1, f+1, sum});
		//cout << i+1 << " " << f+1 << " " << sum << "\n";
		sum += (1 << i);
	}

	cout << f+1 << " " << edges.size() << "\n";
	for(auto e : edges) {
		cout << e[0] << " " << e[1] << " " << e[2] << "\n";
	}

	return 0;
}
