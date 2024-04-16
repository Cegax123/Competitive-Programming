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

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
long long random(long long l, long long r){
   return uniform_int_distribution<long long>(l,r)(rng);
}

const int mod = 998244353;
const int maxn = 6e5 + 5;
int f[maxn], ivf[maxn];

int ex(int a, int b) {
    int ans = 1;
    while(b) {
        if(b&1) ans = ans * 1ll * a % mod;
        b >>= 1;
        a = a * 1ll * a % mod;
    }
    return ans;
}

int g(int n) {
    return ex(n+1, mod-2) * 1ll * f[2 * n] % mod * ivf[n] % mod * ivf[n] % mod;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    f[0] = 1;

    for(int i = 1; i < maxn; i++) 
        f[i] = f[i-1] * 1ll * i % mod;

    ivf[maxn-1] = ex(f[maxn-1], mod-2);

    for(int i = maxn-2; i >= 0; i--) 
        ivf[i] = ivf[i+1] * 1ll * (i+1) % mod;

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<ll> p(n+5, 0);

        for(int i = 0; i < k; i++) {
            ll r = random(1ll, (ll) 1e18);
            
            int L, R; cin >> L >> R;

            p[L] ^= r;
            p[R+1] ^= r;
        }

        for(int i = 1; i <= n; i++)
            p[i] ^= p[i-1];

        sort(p.begin()+1, p.begin()+n+1);

        int ind = 1;

        ll ans = 1;

        while(ind <= n) {
            int cnt = 0;
            ll curr = p[ind];

            while(ind <= n and curr == p[ind]) {
                ind++;
                cnt++;
            }

            if(cnt&1) ans = 0;
            else ans = ans * 1ll * g(cnt/2) % mod;
        }

        cout << ans << "\n";
    }
	
    return 0;
}


