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
		int a[n], l = 0, r = n-1;

		for(int i = 0; i < n; i++) {
			int x; cin >> x;

			if(x&1) {
				a[r] = x;
				r--;
			}
			else {
				a[l] = x;
				l++;
			}
		}

		int ans = 0;
		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				ans += (__gcd(a[i], 2*a[j]) > 1);
			}
		}

		cout << ans << "\n";
	}

	
	return 0;
}
