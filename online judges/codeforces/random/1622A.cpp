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
		vi l; int a;

		for(int i = 0; i < 3; i++) {
			cin >> a; l.pb(a);
		}

		sort(all(l));

		if(l[2] == l[0] + l[1] or (l[2] == l[1] and l[0] % 2 == 0) or (l[0] == l[1] and l[2] % 2 == 0) ) cout << "YES\n";
		else cout << "NO\n";
	}
	
	
	return 0;
}

