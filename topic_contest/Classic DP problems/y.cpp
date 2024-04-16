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

const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;

ll ex(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b&1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int f[maxn], ivf[maxn];

    f[0] = 1;

    for(int i = 1; i < maxn; i++)
        f[i] = f[i-1] * 1ll * i % mod;

    ivf[maxn-1] = ex(f[maxn-1], mod-2);

    for(int i = maxn-2; i >= 0; i--) 
        ivf[i] = ivf[i+1] * 1ll * (i+1) % mod;

    auto comb = [&](int x, int y) {
        return f[x] * 1ll * ivf[y] % mod * ivf[x-y] % mod;
    };

    int h, w, n; cin >> h >> w >> n;
    vii s;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        x--; y--;

        s.pb({x, y});
    }

    s.pb({h-1, w-1});
    sort(all(s));

    int dp[n+1];

    for(int i = 0; i <= n; i++) {
        dp[i] = comb(s[i].first + s[i].second, s[i].first);

        for(int j = 0; j < i; j++) {
            if(s[j].second > s[i].second) continue;
            dp[i] -= dp[j] * 1ll * comb(s[i].first-s[j].first + s[i].second-s[j].second, s[i].first-s[j].first) % mod;
            dp[i] %= mod;
            if(dp[i] < 0) dp[i] += mod;
        }
    }

    cout << dp[n] << "\n";
	
    return 0;
}


