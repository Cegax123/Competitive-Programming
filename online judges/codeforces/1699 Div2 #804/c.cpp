#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

ll ex(ll a, ll b, ll c) {
    ll ans = 1;
    while(b) {
        if(b&1) ans = ans * a % c;
        b >>= 1;
        a = a * a % c;
    }

    return ans;
}

bool cmp(vi a, vi b) {
    int n = a.size();
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            vi visa(n+1, 0), visb(n+1, 0);
            for(int k = i; k <= j; k++) {
                visa[a[k]] = 1;
                visb[b[k]] = 1;
            }

            for(int k = 0; k < n; k++) {
                if(!visa[k] and !visb[k]) break;
                if(!visa[k] or !visb[k]) return false;
            }
        }
    }

    return true;
}

ll find(vi a) {
    vi tmp = a;
    sort(a.begin(), a.end());
    int cnt = 0;
    do {
        cnt += cmp(tmp, a);
    } while(next_permutation(a.begin(), a.end()));
    return cnt;
}

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
long long random(long long l, long long r){
    return uniform_int_distribution<long long>(l,r)(rng);
}

vi generate(int n) {
    vi a(n);
    iota(a.begin(), a.end(), 0);

    vi ans(n);

    for(int i = 0; i < n; i++) {
        int pos = random(0, n-i-1);
        ans[i] = a[pos];
        for(int j = pos; j+1 < n; j++)
            a[j] = a[j+1];
    }

    return ans;
}

int main() {
    const int maxn = 1e5+5;
    const ll mod = (ll) 1e9+7;
    ll f[maxn];

    f[0] = 1;

    for(int i = 1; i < maxn; i++) {
        f[i] = f[i-1] * i % mod;
    }

    ll ivf[maxn];
    ivf[maxn-1] = ex(f[maxn-1], mod-2, mod);

    for(int i = maxn-2; i >= 0; i--) {
        ivf[i] = ivf[i+1] * (i+1) % mod;
    }

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vi a(n);
        int pos[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            pos[a[i]] = i;
        }

        int L = pos[0], R = pos[0];

        ll ans = 1;
        for(int i = 1; i < n; i++) {
            if(pos[i] >= L and pos[i] <= R) {
                ans = ans * (R-L+1 - i) % mod;
            }
            else {
                L = min(L, pos[i]);
                R = max(R, pos[i]);
            }
        }

        cout << ans << "\n";
    }


    return 0;
}
