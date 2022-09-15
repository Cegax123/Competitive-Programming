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

const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;
int sieve[maxn];
ll phi[maxn];

void gen() {
    for(int i = 2; i < maxn; i++) {
        if(sieve[i]) continue;
        sieve[i] = i;

        for(int j = 2; i * j < maxn; j++) {
            if(sieve[i * j]) continue;
            sieve[i * j] = i;
        }
    }

    phi[1] = 1;

    for(int i = 2; i < maxn; i++) {

        if(sieve[i] == i) {
            phi[i] = i-1;
            continue;
        }

        int d = sieve[i];

        int tmp = i;
        int result = 1;

        while(tmp % d == 0) { 
            result *= d;
            tmp /= d;
        }

        if(tmp == 1) phi[i] = i - i / d;
        else phi[i] = phi[tmp] * phi[result] % mod;
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    gen();
    int n; cin >> n;

    ll ans = 0;

    for(ll k = 1; k <= n; k++) {
        for(ll c = n % k; c <= n; c += k) {
            if(c == 0) continue;

            ll val = c * k / __gcd(c, k);
            val %= mod;
            
            
            ll t = (n-c) / k;

            if(t == 1) continue;

            ans += val * phi[t] % mod;
            ans %= mod;
        }
    }

    cout << ans << "\n";

	
    return 0;
}


