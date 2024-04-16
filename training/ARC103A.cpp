#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	map<int, int> cnt1, cnt2;

	for(int i = 0; i < n; i++) {
		int v; cin >> v;
		if(i&1) cnt1[v]++;
		else cnt2[v]++;
	}

	cnt1[-1] = 0;
	cnt2[-1] = 0;

	vector<pair<int, int>> s1, s2;

	for(auto e : cnt1) s1.push_back({e.second, e.first});
	for(auto e : cnt2) s2.push_back({e.second, e.first});

	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());

	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	int ans = 0;

	if(s1[0].second != s2[0].second) ans = max(ans, s1[0].first + s2[0].first);
	else {
		ans = max(ans, s1[0].first + s2[1].first);
		ans = max(ans, s1[1].first + s2[0].first);
	}

	cout << n-ans << "\n";

	return 0;
}
