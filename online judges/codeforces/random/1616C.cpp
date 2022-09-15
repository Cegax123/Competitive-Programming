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

const int maxa = 200;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vi a(n);

		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}

		int ans = 1;

		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				int r = a[j]-a[i];
				int d = j-i;

				int cnt = 0;

				for(int k = 0; k < n; k++) {
					int diffa = a[i]-a[k];
					if(k > i) diffa = a[k]-a[i];

					int diff_ind = abs(i-k);

					if(diffa * d == diff_ind * r) cnt++;
				}

				ans = max(ans, cnt);
			}
		}
		cout << n-ans << "\n";
	}
	
	return 0;
}

