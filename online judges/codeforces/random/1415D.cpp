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
	int n; cin >> n;

	if(n >= 100) {
		cout << "1\n";
		return 0;
	}

	int xo[n+1];
	int a[n+1];
	xo[0] = 0;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		xo[i] = xo[i-1]^a[i];
	}


	int ans = n;
	for(int l = 1; l <= n; l++) {
		for(int r = l+1; r <= n; r++) {
			for(int i = l; i <= r-1; i++) {
				if((xo[i]^xo[l-1]) > (xo[r]^xo[i]))
					ans = min(ans, r-l-1);
			}
		}
	}

	if(ans == n) cout << "-1\n";
	else cout << ans << "\n";
	
	return 0;
}