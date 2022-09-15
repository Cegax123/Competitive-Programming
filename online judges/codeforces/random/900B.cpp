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
	int a, b, c; cin >> a >> b >> c;
	int ans = b+5;

	a *= 10;

	for(int i = 1; i <= b+5; i++) {
		int res = a/b;

		if(res == c) ans = min(ans, i);

		a %= b;
		a *= 10;
	}

	if(ans == b+5) ans = -1;
	cout << ans << " ";
	
	return 0;
}