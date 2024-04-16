#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef vector<int> vi;

const int mod = 998244353;

int ex(int a, int b) {
    int ans = 1;
    while(b) {
        if(b&1) ans = ans * 1ll * a % mod;
        a = a * 1ll * a % mod;
        b >>= 1;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;

    int iv6 = ex(6, mod-2);
    int curr = 1;

    vi dp(1, 1);

    int ans = 0;

    for(int i = 1; i <= k; i++) {
        curr = curr * 1ll * iv6 % mod;

        //cout << curr << endl;

        vi ndp((int) dp.size() + 6, 0);

        for(int j = 1; j <= 6; j++) {
            for(int k = j; k < (int) ndp.size(); k++) {
                ndp[k] += dp[k-j];
            }
        }

        while((int) ndp.size() > n+1) ndp.pop_back();

        dp = ndp;

        if(n < (int) ndp.size()) {
            ans += curr * 1ll * ndp[n] % mod;
            ans %= mod;
        }
    }

    ans = ans * 1ll * ex(k, mod-2) % mod;

    cout << ans << "\n";

    return 0;
}
