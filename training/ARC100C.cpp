#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;
int a[maxn];

int main() {
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] -= i+1;
	}
	
	sort(a, a+n);
	ll curr = 0;
	
	for(int i = 0; i < n; i++) {
		curr += a[i] - a[0];
	}
	
	ll ans = curr;
	
	for(int i = 1; i < n; i++) {
		int d = a[i] - a[i-1];
		curr -= (n-i) * 1ll * d;
		curr += i * 1ll * d;
		ans = min(ans, curr);
	}
	
	cout << ans << "\n";
	
	return 0;
}
