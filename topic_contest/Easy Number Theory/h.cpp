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

const int maxn = 1e7 + 5;
int lp[maxn];
vi primes;

int bf(int x) {
    int cnt = 0;
    for(int i = 1; i <= x; i++) {
        for(int j = i; j <= x; j++) {
            if(i * 1ll * j == __gcd(i, j) * 1ll * x) cnt++;
        }
    }
    return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    for(int i = 2; i < maxn; i++) {
        if(lp[i] == 0) {
            lp[i] = i;
            primes.pb(i);
        }

        for(int j = 0; j < (int) primes.size() and i * primes[j] < maxn; j++) {
            lp[i * primes[j]] = primes[j];
            if(lp[i] <= primes[j]) break;
        }
    }

    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        cout << "Case " << tc << ": ";
        ll n; cin >> n;

        ll ans = 1;
        for(ll p : primes) {
            int cnt = 0;
            while(n % p == 0) {
                n /= p;
                cnt++;
            }

            ans *= 2 * cnt + 1;
        }

        if(n != 1) {
            ans *= 3;
        }

        cout << ans / 2 + 1 << "\n";
    }

    return 0;
}


