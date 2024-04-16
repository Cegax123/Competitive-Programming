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

const int mod = 998244353;
const int maxn = 1e3 + 5;

int ex(int a, int b, int c) {
    int ans = 1;
    while(b) {
        if(b&1) ans = ans * 1ll * a % c;
        a = a * 1ll * a % c;
        b >>= 1;
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int f[maxn];
    f[0] = 1;

    for(int i = 1; i < maxn; i++) 
        f[i] = f[i-1] * 1ll * i % mod;

    int ivf[maxn];
    ivf[maxn-1] = ex(f[maxn-1], mod-2, mod);
    
    for(int i = maxn-2; i >= 0; i--) 
        ivf[i] = ivf[i+1] * 1ll * (i+1) % mod;

    int p2[maxn];
    p2[0] = 1;

    for(int i = 1; i < maxn; i++)
        p2[i] = p2[i-1] * 2 % mod;

    auto comb = [&](int n, int k) {
        if(k < 0) return 0ll;
        if(n < k) return 0ll;
        return f[n] * 1ll * ivf[k] % mod * ivf[n-k] % mod;
    };

    auto g = [&](int n, int k) {
        if(k < 0) return 0ll;
        if(n < k) return 0ll;
        return comb(n, k) * 1ll * ex(p2[n], mod-2, mod) % mod;
    };

    int n, q; cin >> n >> q;
    int a[n], b[n];
    
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    while(q--) {
        int l, r; cin >> l >> r; l--; r--;

        int d = 0, A = 0, B = 0;

        for(int i = 0; i < n; i++) {
            if(i >= l and i <= r) {
                d += a[i];
                B += b[i];
            }
            else {
                d -= a[i];
                A += b[i];
            }
        }

        d = -d + 1;

        int ans = 0;
        for(int i = 0; i <= -d; i++) {
            ans = (ans + g(A, i)) % mod;
        }

        for(int i = -d+1; i <= A; i++) {
            int curr = 0;
            for(int j = d + i; j <= B; j++) {
                curr = (curr + g(B, j)) % mod;
            }

            ans = (ans + g(A, i) * 1ll * curr % mod) % mod;
        }

        cout << ans << "\n";
    }

	
    return 0;
}


