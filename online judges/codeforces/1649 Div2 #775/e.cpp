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

struct BIT {
    vector<int> bit;  // binary indexed tree
    int n;

    BIT(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    BIT(vector<int> a) : BIT(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        if(l > r) return 0;
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

ll ex(ll a, ll b, ll c) {
    ll ans = 1;
    while(b) {
        if(b&1) ans = ans * a % c;
        b >>= 1;
        a = a * a % c;
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    const ll mod = 998244353;
    const int lmt = 2e5 + 5;
    
    ll f[lmt];
    f[0] = 1;

    for(int i = 1; i < lmt; i++) 
        f[i] = f[i-1] * i % mod;

    ll ivf[lmt];
    ivf[lmt-1] = ex(f[lmt-1], mod-2, mod);

    for(int i = lmt-2; i >= 0; i--) {
        ivf[i] = ivf[i+1] * (i+1) % mod;
    }

    BIT ft(lmt);

    int n, m; cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        ft.add(x, 1);
    }

    ll den = 1;

    for(int i = 0; i < lmt; i++) {
        den = den * ivf[ft.sum(i, i)] % mod;
    }

    vi a;
    vi cnt(lmt, 0);

    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        a.pb(x);
        if(i < n) cnt[x]++;
    }

    ll ans = 0;

    if(n < m) {
        bool cmp = 1;
        for(int i = 0; i < n; i++) {
            if(cnt[a[i]] != ft.sum(a[i], a[i])) cmp = 0;
        }
        if(cmp) ans++;
    }

    for(int i = 0; i < m; i++) {
        int x = a[i];
        int cntx = ft.sum(x, x);

        int T = ft.sum(0, lmt-1);

        ll curr = f[T-1] * den % mod * ft.sum(0, x-1) % mod;

        ans = (ans + curr) % mod;

        den = den * f[cntx] % mod;
        den = den * ivf[cntx-1] % mod;
        ft.add(x, -1);
        
        if(cntx == 0) break;
    }

    cout << ans << "\n";
	
    return 0;
}


