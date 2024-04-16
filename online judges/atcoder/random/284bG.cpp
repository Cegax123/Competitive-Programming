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

ll ex(ll a, ll b, ll c) {
	ll ans = 1;

	while(b > 0) {
		if(b&1) ans = (ans * a) % c;
		a = (a * a) % c;
		b >>= 1;
	}

	return ans;
}

ll f[maxn], fact[maxn];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n, m; cin >> n >> m;

    f[1] = 1;

    for(int i = 2; i <= n; i++)
        f[i] = f[i-1] * (n-i+1) % m;

    fact[0] = 1;
    
    for(int i = 1; i <= n; i++) {
        fact[i] = fact[i-1] * i % m;
    }

    ll ans = 0;

    auto mul = [&](ll a, ll b) {
        return a * b % m;
    };

    for(int g = 1; g <= n; g++) {
        ll k = n-g;
        if(k == 0) k = 1;

        ans = (ans + mul(f[g], mul(ex(k, n, m), g))) % m;
    }

    cout << ans << "\n";

    return 0;
}


