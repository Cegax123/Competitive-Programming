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

bool isP(int n) {
	for(int i = 2; i*i <= n; i++)
		if(n%i == 0) return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	vi p;

	for(int i = 2; i <= 100; i++)
		if(isP(i)) p.pb(i);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		
		for(int i = 0; i < (int) p.size(); i++) {
			if(__gcd(p[i], n-p[i]-1)==1) {
				cout << p[i] << " " << n-p[i]-1 << " " << 1 << "\n";
				break;
			}
		}
	}

	return 0;
}
