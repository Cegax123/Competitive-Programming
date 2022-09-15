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
	int n, m; cin >> n >> m;

	if(n == 1) {
		cout << 1 << "\n";
	}
	else {
		if(m == 1) {
			cout << 2 << "\n";
		}
		else if(m == n) {
			cout << n-1 << "\n";
		}
		else {
			if(n-m > m-1) {
				cout << m+1 << "\n";
			}
			else {
				cout << m-1 << "\n";
			}
		}
	}

	return 0;
}