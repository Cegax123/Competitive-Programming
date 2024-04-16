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

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

int f[maxn], ivf[maxn];

int ex(int a, int b, int c) {
    int ans = 1;
    while(b) {
        if(b&1) ans = ans * 1ll * a % c;
        a = a * 1ll * a % c;
        b >>= 1;
    }
    return ans;
}

int comb(int n, int k) {
    return f[n] * 1ll * ivf[k] % mod * ivf[n-k] % mod;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    f[0] = 1;
    for(int i = 1; i < maxn; i++) f[i] = f[i-1] * 1ll * i % mod;
    ivf[maxn-1] = ex(f[maxn-1], mod-2, mod);

    for(int i = maxn-2; i >= 0; i--) {
        ivf[i] = ivf[i+1] * 1ll * (i+1) % mod;
    }

    int t; cin >> t;
    while(t--) {
        int n, m1, m2; cin >> n >> m1 >> m2;
        int l[m1], r[m2];

        for(int i = 0; i < m1; i++) cin >> l[i];
        for(int i = 0; i < m2; i++) cin >> r[i];

        if(l[m1-1] != r[0] or l[0] != 1 or r[m2-1] != n) {
            cout << 0 << "\n";
            continue;
        }

        int mid = l[m1-1];
        int ans = comb(n-1, mid-1);

        for(int i = m1-1; i >= 1; i--) {
            ans = ans * 1ll * comb(l[i]-2, l[i]-l[i-1]-1) % mod;
            ans = ans * 1ll * f[l[i]-l[i-1]-1] % mod;
        }

        for(int i = 0; i + 1 < m2; i++) {
            ans = ans * 1ll * comb(n - r[i] - 1, r[i+1]-r[i]-1) % mod;
            ans = ans * 1ll * f[r[i+1]-r[i]-1] % mod;
        }

        cout << ans << "\n";
    }
	
    return 0;
}

