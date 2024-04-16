#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define pb push_back
#define all(c) (c).begin(), (c).end()

const ll mod = 998244353;


ll ex(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b&1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}

int main() {
    int n, m, K; cin >> n >> m >> K;
    vi cnt(m+2, 0), cntR(m+2, 0);

    K = n-K + 1;

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        cnt[a]++;
    }

    for(int i = m; i >= 0; i--) {
        cntR[i] = cnt[i] + cntR[i+1];
    }

    const int maxn = 2005;
    ll f[maxn];

    f[0] = 1;

    for(int i = 1; i < maxn; i++)
        f[i] = f[i-1] * i % mod;

    auto comb = [&](ll x, ll y) {
        ll den = ex(f[y], mod-2) * ex(f[x-y], mod-2) % mod;
        return f[x] * den % mod;
    };

    ll ans = 0;
    for(int i = 1; i <= m; i++) {
        int ind = 1;
        ll total = 0;
        while(ind <= n) {
            int p = cnt[0] - max(0, ind-cnt[i]);
            int needR = K-1-cntR[i+1]-(ind-1);
            int needL = p - needR;


            if(needL < 0 or needR < 0) {
                ind++;
                continue;
            }
            if(i == m and needR) {
                ind++;
                continue;
            }

            ll curr = ex(m-i, needR) % mod * ex(i, needL) % mod;

            //cout << curr <<  " " << cnt[0] << " " << max(0, ind-cnt[i]) << " " << p << " " << needR << endl;
            curr = curr * comb(cnt[0], max(0, ind-cnt[i])) % mod * comb(p, needR) % mod;


            total += curr;
            
            total %= mod;

            ind++;

        }

        //cout << i << " " << total << endl;
        ans = (ans + total * i % mod) % mod;
    }

    ans = ans * ex(ex(m, cnt[0]), mod-2) % mod;

    cout << ans << "\n";


    return 0;
}
