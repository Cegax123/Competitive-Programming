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
		int a[n], b[n], c[n];

		for(int i = 0; i < n; i++)
			cin >> a[i] >> b[i] >> c[i];

		set<int> l, r, both;

		int L = a[0], R = b[0];

		l.insert(c[0]);
		r.insert(c[0]);
		both.insert(c[0]);

		cout << c[0] << "\n";

		for(int i = 1; i < n; i++) {
			int nL = min(L, a[i]), nR = max(R, b[i]);

			if(nL != L) {
				l.clear();
				both.clear();
			}
			if(nR != R) {
				r.clear();
				both.clear();
			}

			if(nL == a[i] and nR == b[i]) {
				both.insert(c[i]);
				l.insert(c[i]);
				r.insert(c[i]);
			}
			else if(nL == a[i]) l.insert(c[i]);
			else if(nR == b[i]) r.insert(c[i]);

			L = nL;
			R = nR;

			int ans = (int) 2e9;

			if(!both.empty()) ans = *(both.begin());
			if(!l.empty() and !r.empty()) ans = min(ans, (*l.begin()) + (*r.begin()));

			cout << ans << "\n";
		}
	}
	
	return 0;
}

