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
	int n, m; cin >> n >> m;

	if(n > m) {
		cout << 0 << "\n";
	}
	else {
		int a[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}

		int ans = 1;

		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				ans = ans * abs((a[j]-a[i])%m) % m;
			}
		}

		cout << ans << "\n";
	}

	
	return 0;
}