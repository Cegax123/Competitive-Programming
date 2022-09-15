#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//cout << setprecision(12) << fixed;



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while(t--) {
		int n, k; cin >> n >> k;
		vi a(n);
		vii b(n);

		for(int i = 0; i < n; i++) {
			cin >> a[i];
			b[i].first = a[i];
			b[i].second = i;
		}

		sort(all(b));
		for(int i = 0; i < n; i++) {
			a[b[i].second] = i;	
		}

		int ans = 0;
		int i = 0;

		while(i < n) {
			if(i == n-1) {
				ans++;
				i++;
				continue;
			}

			while(i+1 < n and a[i]+1 == a[i+1]) {
				i++;
			}

			i++;
			ans++;
		}
		if(ans <= k) cout << "Yes\n";
		else cout << "No\n";
	}

	
	return 0;
}