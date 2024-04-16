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

const ll mod = 998244353;

ll ex(ll a, ll b, const ll c) {
    ll ans = 1;
    while(b) {
        if(b&1) ans = ans * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, l, r; cin >> n >> m >> l >> r;

    if((n&1) and (m&1)) {
        cout << ex(r-l+1, n * 1ll * m, mod) << "\n";
    }
    else {
        int e = (r-l+1) / 2, o = (r-l+1) - e;

        ll ans = (ex(e + o, n * 1ll * m, mod) + ex(e - o, n * 1ll * m, mod)) % mod;
        ans = ans * ex(2, mod-2, mod) % mod;

        cout << ans << "\n";
    }

	
    return 0;
}


