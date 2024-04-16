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

	while(b > 0) {
		if(b&1) ans = (ans * a) % c;
		a = (a * a) % c;
		b >>= 1;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    const int maxn = 4e5 + 5;
    const ll mod = 998244353;

    auto mul = [&](ll a, ll b) {
        return a * b % mod;
    };

    ll f[maxn];
    f[0] = 1;

    for(int i = 1; i < maxn; i++)
        f[i] = mul(f[i-1], i);

    ll ivf[maxn];
    ivf[maxn-1] = ex(f[maxn-1], mod-2, mod);

    for(int i = maxn-2; i >= 0; i--)
        ivf[i] = mul(ivf[i+1], i+1);

    auto comb = [&](ll a, ll b) {
        return mul(f[a], mul(ivf[a-b], ivf[b]));
    };

    int n, k; cin >> n >> k;
    bool cnt[maxn];

    memset(cnt, 0, sizeof(cnt));

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        cnt[a] = 1;
    }

    vi b;
    int ind = 0;

    while((int) b.size() < k) {
        int curr = 1;
        
        ind++;

        while(cnt[ind-1]) {
            curr++;
            ind++;
        }

        b.pb(curr);
    }

    ll accum = 0;
    ll ans = 0;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < b[i]; j++) {
            accum++;
            ans += comb(k-i -1 + accum - 1, accum-1);
            ans %= mod;
        }
    }


	
    cout << ans << "\n";

    return 0;
}


