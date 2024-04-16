#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const int mod = 1e9+7;
int dp[maxn];
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

void gen() {
    f[0] = 1;
    for(int i = 1; i < maxn; i++) {
        f[i] = f[i-1] * 1ll * i % mod;
    }

    ivf[maxn-1] = ex(f[maxn-1], mod-2, mod);

    for(int i = maxn-2; i >= 0; i--) {
        ivf[i] = ivf[i+1] * 1ll * (i+1) % mod;
    }
}

int comb(int n, int k) {
    return f[n] * 1ll * ivf[k] % mod * ivf[n-k] % mod;
}

int main() {
    gen();

    dp[0] = 1;

    for(int i = 1; i < maxn; i++) {
        dp[i] = dp[i-1];

        if(i >= 2) {
            dp[i] += (i-1) * 1ll * dp[i-2] % mod;
            dp[i] %= mod;
        }
        if(i >= 4) {
            dp[i] += comb(i-1, 3) * 1ll * dp[i-4] % mod * 6 % mod;
            dp[i] %= mod;
        }
    }

    int n; cin >> n;
    int s[n];
    int p[n];
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        cnt += i == s[i];
        p[s[i]] = i;
    }
    
    bool cmp = 1;
    for(int i = 0; i < n; i++) {
        int x = s[i];
        for(int j = 0; j < 4; j++) {
            x = p[x];
        }

        if(x != i) cmp = 0;
    }

    if(cmp == 0) {
        cout << 0 << "\n";
        return 0;
    }

    cout << dp[cnt] << endl;

    return 0;
}
