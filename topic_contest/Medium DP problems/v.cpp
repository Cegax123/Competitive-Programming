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



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vi primes;
    const int maxn = 1005;
    int sieve[maxn];
    memset(sieve, 0, sizeof(sieve));

    primes.pb(1);
    for(int i = 2; i < maxn; i++) {
        if(sieve[i]) continue;
        primes.pb(i);

        for(int j = 2; i * j < maxn; j++) {
            sieve[i * j] = 1;
        }
    }

    int n; cin >> n;
    
    const int LOGN = 15;
    const ll INF = 1e18 + 1e15;

    ll dp[n+1][LOGN];
    memset(dp, -1, sizeof(dp));

    dp[1][0] = 1;

    for(int d = 2; d <= n; d++) {
        for(int j = 1; j < LOGN; j++) {
            for(int k = 1; k < d; k++) {
                if(d % k) continue;
                if(dp[k][j-1] == -1) continue;
                int c = d / k - 1;
                ll p = primes[j];

                ll pc = 1;

                for(int i = 0; i < c; i++) {
                    if(pc > INF / p) {
                        pc = INF;
                        break;
                    }
                    else pc *= p;
                }

                if(pc == INF) continue;

                if(dp[k][j-1] < INF / pc) {
                    if(dp[d][j] == -1) dp[d][j] = dp[k][j-1] * pc;
                    else dp[d][j] = min(dp[d][j], dp[k][j-1] * pc);
                }
            }
        }
    }

    ll ans = INF;

    for(int i = 0; i < LOGN; i++)
        if(dp[n][i] != -1) ans = min(ans, dp[n][i]);

    cout << ans << "\n";
	
    return 0;
}


