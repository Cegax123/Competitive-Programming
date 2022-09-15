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
		string s; cin >> s;
		int n = s.size();

		ll ans = 0; 
		int e0 = 1, e1 = 1;

		if(s[0] == '0') e1 = 0;
		else if(s[0] == '1') e0 = 0;

		ans = max(e0, e1);

		for(int i = 1; i < n; i++) {
			int te0 = e1+1, te1 = e0+1;

			if(s[i] == '0') te1 = 0;
			else if(s[i] == '1') te0 = 0;

			ans += (ll) max(te0, te1);

			// cout << te0 << " " << te1 << "\n";

			e0 = te0; e1 = te1;
		}

		cout << ans << "\n";
	}


	
	return 0;
}