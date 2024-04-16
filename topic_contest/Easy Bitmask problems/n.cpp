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

const int L = 61;

ll ex(ll a, ll b, ll c) {
	ll ans = 1;

	while(b > 0) {
		if(b&1) ans = (ans * a) % c;
		a = (a * a) % c;
		b >>= 1;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int r; cin >> r;
        ll n; cin >> n; n = n * n;
        int m; cin >> m;

        int f[L];
        f[0] = 1 % m;
        
        int prod = r % m;

        for(int i = 1; i < L; i++) {
            f[i] = (f[i-1] + prod * 1ll * f[i-1] % m) % m;
            prod = prod * 1ll * prod % m;
        }

        ll ans = 0;
        ll sum = 0;
        for(int i = 0; i < L; i++) {
            if(n&(1ll << i)) {
                ans += ex(r, sum, m) * 1ll * f[i] % m;
                ans %= m;

                sum += (1ll << i);
            }
        }

        cout << ans << "\n";
    }

	
    return 0;
}


