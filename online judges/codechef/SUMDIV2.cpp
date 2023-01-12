
#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define pb push_back 
typedef long long ll;
typedef pair<int, int > ii;
typedef vector<int> vi;
typedef vector<ii> vii;



int main() {
	int t; cin >> t;
	while(t--) {
	    ll x, y; cin >> x >> y;
	    
	    if(x > y) swap(x, y);
	    
	    if(x == y) cout << x << "\n";
	    else {
	        ll g = __gcd(x, y);
			ll f = (x == g ? (2 * x/g-1) : x/g - 1);
	        cout << y * f - x << "\n";
	    }
	}

		
	return 0;
}

