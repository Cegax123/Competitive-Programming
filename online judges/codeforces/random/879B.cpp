#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; long long k; cin >> n >> k;
	deque<int> a(n);

	for(int i = 0; i < n; i++) cin >> a[i];

	int last = -1;
	int cnt = 0;

	for(int i = 0; i < 2 * n; i++) {
		int w = max(a[0], a[1]);

		if(w == last) cnt++;
		else {
			last = w;
			cnt = 1;
		}

		if(cnt == k) {
			cout << w << "\n";
			return 0;
		}

		if(a[0] < a[1]) {
			a.push_back(a[0]);
			a.pop_front();
		}
		else {
			a.push_back(a[1]);
			int x = a[0];
			a.pop_front();
			a.pop_front();
			a.push_front(x);
		}

	}

	cout << a[0] << "\n";

	return 0;
}
