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
    while(b) {
        if(b&1) ans = ans * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    const int maxn = 500;
    const int mod = 1e9 + 7;

    int f[maxn], ivf[maxn];
    f[0] = 1;

    for(int i = 1; i < maxn; i++) 
        f[i] = f[i-1] * 1ll * i % mod;

    ivf[maxn-1] = ex(f[maxn-1], mod-2, mod);

    for(int i = maxn-2; i >= 0; i--)
        ivf[i] = ivf[i+1] * 1ll * (i+1) % mod;

    auto comb = [&](int x, int y) {
        if(x < 0 or y < 0) return 0ll;
        if(y > x) return 0ll;
        return f[x] * 1ll * ivf[y] % mod * ivf[x-y] % mod;
    };

    int t; cin >> t;
    while(t--) {
        int n, i, j, x, y; cin >> n >> i >> j >> x >> y;

        if(x > y) {
            swap(x, y);
            i = n + 1 - i;
            j = n + 1 - j;
            swap(i, j);
        }



        if(y == n) {
            ll ans = comb(n-x-1, j-i-1) * comb(x-1, i-1) % mod;
            if(x == i and y == j) ans--;
            if(ans < 0) ans += mod;

            cout << ans << "\n";
        }
        else {
            ll ans = 0;

            for(int k = i+1; k < j; k++) {
                ans += comb(n-y-1, j-k-1) * comb(y-x-1, j+y-i-n-1) % mod * comb(x-1, i-1) % mod;
                ans %= mod;
            }

            for(int k = j + 1; k <= n; k++) {
                ans += comb(n-y-1, k-j-1) * comb(y-x-1, j-i-1) % mod * comb(x-1, i-1) % mod;
                ans %= mod;
            }

            if(x == i and y == j) ans--;
            if(ans < 0) ans += mod;

            cout << ans << "\n";
        }
    }

	
    return 0;
}


