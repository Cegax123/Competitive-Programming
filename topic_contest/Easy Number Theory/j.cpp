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
vi primes;
int lp[maxn];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i = 2; i < maxn; i++) {
        if(lp[i] == 0) {
            lp[i] = i;
            primes.pb(i);
        }

        for(int j = 0; j < (int) primes.size() and lp[i] >= primes[j] and i * primes[j] < maxn; j++) {
            lp[i * primes[j]] = primes[j];
        }
    }

    int t; cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        cout << "Case " << tt << ": ";

        ll x; cin >> x;
        bool neg = x < 0ll;
        x = abs(x);

        int ans = 0;
        for(int p : primes) {
            int cnt = 0;
            while(x % p == 0) {
                cnt++;
                x /= p;
            }

            ans = __gcd(ans, cnt);
        }

        if(x != 1) ans = __gcd(ans, 1);

        if(neg) while(ans % 2 == 0) ans /= 2;

        cout << ans << "\n";
    }

	
    return 0;
}


