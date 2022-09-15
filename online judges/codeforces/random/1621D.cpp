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
		int n; cin >> n;

		int c[2*n][2*n];
		ll ans = 0;

		for(int i = 0; i < 2*n; i++) {
			for(int j = 0; j < 2*n; j++) {
				cin >> c[i][j];
				if(i >= n and j >= n) {
					ans += (ll) c[i][j];
					c[i][j] = 0;
				}
			}
		}

		ll add = min({c[n-1][n], c[n][n-1], c[2*n-1][n-1], c[n-1][2*n-1], c[n][0], c[0][n], c[0][2*n-1], c[2*n-1][0]});
		cout << ans + add << "\n";

	}
	
	return 0;
}

