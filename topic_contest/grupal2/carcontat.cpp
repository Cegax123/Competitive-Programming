#include<bits/stdc++.h>
using namespace std;

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
    int n; cin >> n;
    int a[n];
    int cc[n];
    vector<int> cnt(11, 0);

    for(int i = 0; i < n; i++) {
        cin >> a[i];

        int x = a[i];
        cc[i] = 0;
        while(x) {
            cc[i]++;
            x /= 10;
        }
        cnt[cc[i]]++;
    }

    const int maxn = 105;
    const int maxs = 1000;
    const int mod = 1e9 + 7;

    int dp[11][maxn][maxs];

    for(int i = 1; i <= 10; i++) {
        if(cnt[i] == 0) continue;
        cnt[i]--;

        dp[i][0][0] = 1;

        for(int j = 1; j <= 10; j++) {
            for(int k = 0; k < cnt[j]; k++) {
                for(int a = n; a >= 0; a--) {
                    for(int b = maxs; b >= j; b--) {
                        dp[i][a][b] = (dp[i][a][b] + dp[i][a-1][b-j]) % mod;
                    }
                }
            }
        }
        cnt[i]++;
    }


    int p[maxs];
    p[0] = 1;

    for(int i = 1; i < maxs; i++) {
        p[i] = p[i-1] * 10ll % mod;
    }

    int f[maxs];
    f[0] = 1;

    for(int i = 1; i < maxs; i++) {
        f[i] = f[i-1] * 1ll * i % mod;
    }

    int ivf[maxs];
    ivf[maxs-1] = ex(f[maxs-1], mod-2, mod);

    for(int i = maxs-2; i >= 0; i--) {
        ivf[i] = ivf[i+1] * 1ll * (i+1) % mod;
    }

    auto comb = [&](int a, int b) {
        return f[a] * 1ll * ivf[b] % mod * ivf[a-b] % mod;
    };
        
    int F[maxs];
    F[0] = 1;

    for(int i = 1; i < maxn; i++) {
        F[i] = 0;
        for(int j = 0; j <= i; j++) {
            F[i] = (F[i] + comb(i, j) * 1ll * f[j] % mod) % mod;
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= n-1; j++) {
            for(int l = 0; l < maxs; l++) {
                int lft = n-1-j;

                //if(dp[cc[i]][j][l]) cout << i << " " << j << " " << l << endl;
                ans = (ans + F[lft] * 1ll * dp[cc[i]][j][l] % mod * p[l] % mod * a[i] % mod * f[j] % mod) % mod;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
