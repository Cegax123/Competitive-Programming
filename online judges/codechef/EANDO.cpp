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
		int k = (n >> 1);

		ll a[n];
		ll sum = 0;

		for(int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}

		if(sum % k) {
			cout << "NO\n";
			continue;
		}

		ll targ = sum / k;

		if((targ&1) == 0) {
			cout << "NO\n";
			continue;
		}

		ll so = 1, se = targ - so;
		ll result = 0;

		for(int i = 0; i < n; i++) {
			if(i < k) 
				result += (so - a[i]) + (so - a[n-1-i]);
			else 
				result += (se - a[i]) + (se - a[n-1-i]);
		}

		if(result == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}	
	
	
    return 0;
}

