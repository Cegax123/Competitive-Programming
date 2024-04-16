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

ll ex(ll a, ll b, ll c) {
	ll ans = 1;

	while(b > 0) {
		if(b&1) ans = (ans * a) % c;
		a = (a * a) % c;
		b >>= 1;
	}

	return ans;
}

const ll mod = (ll) 1e9 + 7;


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    int x[n], y[n];

    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    sort(x, x+n);

    ll ans = 1;

    for(int i = 1; i <= n; i++)
        ans = (ans * ex(i, mod-2, mod)) % mod;

    int ind = 0;
    while(ind < n) {
        int c = x[ind];
        int r = ind;
        while(r < n and x[r] == c) {
            r++;
        }
        r--;

        int len = r-ind+1;

        for(; len >= 1; len--) {
            ans = (ans * len) % mod;
        }
        ind = r+1;
    }

    cout << ans << "\n";
	
    return 0;
}


