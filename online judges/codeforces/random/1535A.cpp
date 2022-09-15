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
	int n; cin >> n;
	while(n--) {
		int a,b,c,d; cin >> a >> b >> c >> d;

		if((a > c and a > d and b > c and b > d) or (a < c and b < c and a < d and b < d)) {
			cout << "NO\n";
		}
		else cout << "YES\n";
	}

	
	return 0;
}
