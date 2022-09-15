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
		int n, a, b; cin >> n >> a >> b;

		if(abs(a-b) > 1 or a+b >= n-1) {
			cout << -1 << "\n";
			continue;
		}

		if(a == 0 and b == 0) {
			for(int i = 0; i < n; i++)
				cout << i+1 << " ";
			cout << "\n";
			continue;
		}

		vi ans;
		if(b > a) {
			int r = n, l = 1;
			for(int i = 0; i < b; i++) {
				ans.pb(r);
				ans.pb(l);

				r--; l++;
			}

			for(int i = l; i <= r; i++)
				ans.pb(i);
		}
		else if(a > b) {
			int r = n, l = 1;
			for(int i = 0; i < a; i++) {
				ans.pb(l); ans.pb(r);
				l++; r--;
			}
			for(int i = r; i >= l; i--)
				ans.pb(i);
		}
		else {
			int l = 1, r = n;
			ans.pb(l);
			l++;
			for(int i = 0; i < a; i++) {
				ans.pb(r);
				ans.pb(l);
				r--; l++;
			}

			for(int i = l; i <= r; i++)
				ans.pb(i);
		}

		for(int i = 0; i < n; i++)
			cout << ans[i] << " ";
		cout << "\n";
	}
	
	
	return 0;
}
