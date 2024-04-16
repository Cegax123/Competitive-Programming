#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;

	priority_queue<int> pq;

	long long ans = 0;
	for(int i = 0; i < n; i++) {
		int a; cin >> a;
		a -= i;

		pq.push(a);
		pq.push(a);

		int opt = pq.top();
		ans = ans + abs(opt-a);
		
		pq.pop();
	}

	cout << ans << "\n";

	return 0;
}
