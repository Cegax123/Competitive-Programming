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
		int n, x; cin >> n >> x;
		int mxA = 0, sum = 0;

		for(int i = 0; i < n; i++) {
			int a; cin >> a;
			mxA = max(mxA, a);

			sum += (a + x - 1) / x;
		}	

		cout << min(mxA, sum) << "\n";
	}	

	
    return 0;
}

