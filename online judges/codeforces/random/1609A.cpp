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

		ll mx = 0;
		ll sum = 0;
		int cnt = 0;

		for(int i = 0; i < n; i++) {
			ll a; cin >> a;
			
			while(a%2==0) {
				a >>= 1;
				cnt++;
			}

			mx = max(mx, a);
			sum += a;
		}

		cout << sum-mx+(mx << cnt) << "\n";
	}
	
	
	return 0;
}
