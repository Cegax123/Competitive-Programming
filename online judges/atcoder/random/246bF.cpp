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
    int n, l; cin >> n >> l;

    const int mod = 998244353;
    const int maxlen = 30;
    ll f[maxlen];

    for(int i = 0; i < maxlen; i++) 
        f[i] = ex(i, l, mod);

    int inter[1 << n];

    for(int i = 0; i < n; i++) {
        int mask = 0;

        string s; cin >> s;
        for(char c : s)
            mask |= (1 << (c-'a'));

        inter[1 << i] = mask;
    }

    ll ans = 0;

    for(int i = 1; i < (1 << n); i++) {
        int parity = __builtin_popcount(i);

        if(parity > 1) {
            int lso = i - (i&(i-1));
            inter[i] = inter[i^lso] & inter[lso];
        }

        int cnt = __builtin_popcount(inter[i]);

        if(parity&1) ans += f[cnt];
        else ans -= f[cnt];

        ans %= mod;
    }

    if(ans < 0) ans += mod;

    cout << ans << "\n";
	
    return 0;
}


