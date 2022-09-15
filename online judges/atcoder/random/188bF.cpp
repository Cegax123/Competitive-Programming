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

map<ll, bool> computed;
map<ll, ll> ans;

ll X, Y;

ll solve(ll y) {
	if(computed[y])
		return ans[y];

	if(y == 1) {
		computed[y] = 1;
		return ans[y] = abs(X-y);
	}
	else if(y&1ll) {
		computed[y] = 1;
		return ans[y] = min({abs(X-y), 2 + solve((y+1)/2), 2 + solve((y-1)/2)});
	}
	else {
		computed[y] = 1;
		return ans[y] = min(abs(X-y), 1 + solve(y/2));
	}
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> X >> Y;
	
	cout << solve(Y) << "\n";
	
    return 0;
}
