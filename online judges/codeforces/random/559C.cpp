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
    int h, w, n; cin >> h >> w >> n;
    vii p;

    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        p.pb({x, y});
    }

    p.pb({h, w});

    sort(all(p));

    const int mod = 1e9 + 7;

    const int maxn = 2e5 + 5;
    int f[maxn];
    f[0] = 1;
    for(int i = 1; i < maxn; i++) f[i] = f[i-1] * 1ll * i % mod;

    int ivf[maxn];
    ivf[maxn-1] = ex(f[maxn-1], mod-2, mod);
    for(int i = maxn-2; i >= 0; i--) ivf[i] = ivf[i+1] * 1ll * (i+1) % mod;

    auto comb = [&](int x, int y) {
        return f[x] * 1ll * ivf[y] %  mod * ivf[x-y] % mod;
    };
    
    int dp[n+1];

    for(int i = 0; i <= n; i++) {
        int x = p[i].first-1, y = p[i].second-1;
        dp[i] = comb(x + y, x);

        for(int j = 0; j < i; j++) {
            if(p[j].first <= p[i].first and p[j].second <= p[i].second) {
                x = p[i].first - p[j].first;
                y = p[i].second - p[j].second;

                dp[i] -= dp[j] * 1ll * comb(x + y, x) % mod;
                dp[i] %= mod;
                if(dp[i] < 0) dp[i] += mod;
            }
        }
    }

    cout << dp[n] << "\n";

    return 0;
}


