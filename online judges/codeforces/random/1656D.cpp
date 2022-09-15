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

bool f(ll x, ll n) {
	if(x == 1) return 0;
	if(x >= 2e9) return 0;
	
	return (x * (x+1) ) / 2 <= n;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		
		if(n&1) {
			cout << 2 << "\n";
		}
		else {
			ll d = 2;
			ll tmp = n;
			
			while((tmp&1)==0) {
				d <<= 1;
				tmp >>= 1;
			}
			
			if(f(d, n)) {
				cout << d << "\n";
			}
			else if(f(tmp, n)) {
				cout << tmp << "\n";
			}
			else {
				cout << -1 << "\n";
			}
		}
	}

	
    return 0;
}
