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

const int maxn = 1e6 + 5;
int lp[maxn];
vi primes;

void init() {

    for(int i = 2; i < maxn; i++) {
        if(lp[i] == 0) {
            lp[i] = i;
            primes.pb(i);
        }

        for(int j = 0; j < (int) primes.size() and i * primes[j] < maxn; j++) {
            lp[i * primes[j]] = primes[j];
            if(primes[j] >= lp[i]) break;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();

    int t; cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        cout << "Case " << tt << ": ";
        ll a, b; cin >> a >> b;

        ll ta = a;

        if(b * b >= a) {
            cout << 0 << "\n";
            continue;
        }

        int ans = 1;
        
        for(int i = 0; i < (int) primes.size() and primes[i] * 1ll * primes[i] <= a; i++) {
            int cnt = 0;
            while(a % primes[i] == 0) {
                a /= primes[i];
                cnt++;
            }
            ans *= cnt+1;
        }

        if(a != 1) ans *= 2;


        ans = ans / 2;

        for(int i = 1; i < b; i++) {
            if(ta % i == 0) ans--;
        }

        cout << ans << "\n";
    }
	
    return 0;
}


