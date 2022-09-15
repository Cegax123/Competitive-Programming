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
		vi a(n);
		int mxa = 0;

		for(int i = 0; i < n; i++) {
			cin >> a[i];
			mxa = max(mxa, a[i]);
		}

		if(mxa == a[n-1]) {
			cout << 0 << "\n";
			continue;
		}

		int k = 0;
		int last = a[n-1];
		for(int i = n-2; i >= 0; i --) {
			if(a[i] > last) {
				k++;
				last = a[i];
				if(a[i] == mxa) break;
			}
		}

		cout << k << "\n";
	}
	
	
	return 0;
}
