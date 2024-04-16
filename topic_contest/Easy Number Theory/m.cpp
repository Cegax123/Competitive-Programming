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
typedef unsigned long long ull;
//cout << setprecision(12) << fixed;

const int maxn = 1e5 + 5;

int lp[maxn];
vi primes;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i = 2; i < maxn; i++) {
        if(lp[i] == 0) {
            lp[i] = i;
            primes.pb(i);
        }

        for(int j = 0; j < (int) primes.size() and i * primes[j] < maxn and lp[i] >= primes[j]; j++) {
            lp[i * primes[j]] = primes[j];
        }
    }

    int t; cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        cout << "Case " << tt << ": ";
        ll a, b; cin >> a >> b;
        ll d = b-a+1;
        
        vi c(d, 0);

        for(int p : primes) {
            ll L = ((a + p - 1) / p) * p, R = (b / p) * p;

            if(a <= L and L <= b and a <= R and R <= b and L <= R) {
                for(int i = L; i <= R; i += p) {
                    if(p != i) c[i-a] = 1;
                }
            }
        }

        if(a == 1) c[0] = 1;

        int cnt = 0;
        for(int x : c) cnt += x == 0;

        cout << cnt << "\n";
    }
	
    return 0;
}


