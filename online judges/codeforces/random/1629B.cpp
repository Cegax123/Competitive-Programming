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
		int l, r, k; cin >> l >> r >> k;
		
		if(l == r) {
			if(l == 1) cout << "NO\n";
			else cout << "YES\n";
			continue;
		}

		int n = r-l-(r/2-(l+1)/2);

		if(k >= n) cout << "YES\n";
		else cout << "NO\n";
	}
	
	
	return 0;
}
