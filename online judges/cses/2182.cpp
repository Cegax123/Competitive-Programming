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

const ll mod = 1e9+7;

ll mul(ll a, ll b) {
    return a*b%mod;
}

ll ex(ll a, ll b) {
	ll ans = 1;

	while(b > 0) {
		if(b&1) ans = (ans * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}

	return ans;
}

ll sum(ll a, ll b) {
    ll ans = (a+b)%mod;
    return (ans+mod)%mod;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    ll x[n], k[n];
    bool even = 1;

    for(int i = 0; i < n; i++) {
        cin >> x[i] >> k[i];
        if(k[i]&1ll)
            even = 0;
    }

    ll cd = 1;

    for(int i = 0; i < n; i++) 
        cd = mul(cd, k[i]+1);
	
    ll sum_div = 1;

    for(int i = 0; i < n; i++) {
        ll num = ex(x[i], k[i]+1);
        num = sum(num, -1);

        ll den = sum(x[i], -1);
        den = ex(den, mod-2);

        sum_div = mul(sum_div, mul(num, den));
    }

    ll prod;
    if(even) {
        ll m = 1;
        for(int i = 0; i < n; i++) 
            m = mul(m, ex(x[i], k[i]/2ll));

        ll cd2 = 1;

        for(int i = 0; i < n; i++) 
            cd2 = cd2 * (k[i]+1)%(mod-1);

        prod = ex(m, cd2);
    }
    else {
        ll cd2 = 1;
        bool found = 0;
        for(int i = 0; i < n; i++) {
            if((k[i]&1ll) and !found) {
                cd2 = cd2*((k[i]+1)/2)%(mod-1);
                found = 1;
            }

            else 
                cd2 = cd2*(k[i]+1)%(mod-1);
        }
            
        ll m = 1;

        for(int i = 0; i < n; i++)
            m = mul(m, ex(x[i], k[i]));

        prod = ex(m, cd2);
    }

    cout << cd << " " << sum_div << " " << prod << "\n";
	
	return 0;
}

