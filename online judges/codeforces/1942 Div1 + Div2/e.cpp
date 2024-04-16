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

const int maxn = 1e6 + 5;
const int mod = 998244353;

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
    for(int i = 1; i < maxn; i++) {
        f[i] = f[i-1] * 1ll * i % mod;
    }

    int ivf[maxn];
    ivf[maxn-1] = ex(f[maxn-1], mod-2, mod);

    for(int i = maxn-2; i >= 0; i--) {
        ivf[i] = ivf[i+1] * 1ll * (i+1) % mod;
    }

    auto comb = [&](int n, int k) {
        return f[n] * 1ll * ivf[k] % mod * ivf[n-k] % mod;
    };

    int t; cin >> t;
    while(t--) {
        int l, n; cin >> l >> n;

        int rest = 0;

        for(int i = 2 * n; i <= l; i++) {
            int k = i;
            k -= 2 * n;

            k /= 2;

            rest = 
        }
    }

	
    return 0;
}


