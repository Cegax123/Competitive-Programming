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
vi primes;
int sieve[maxn];

void gen() {
    sieve[1] = 1;

    for(int i = 2; i < maxn; i++) {
        if(sieve[i]) continue;
        sieve[i] = i;
        for(int j = 2; i * j < maxn; j++) {
            if(sieve[i * j]) continue;
            sieve[i * j] = i;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    gen();

    int n; cin >> n;
    vi cnt(maxn, 0);

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        cnt[a]++;
    }

    int dp[maxn];
    memset(dp, 0, sizeof(dp));

    dp[1] = cnt[1];
    int ans = dp[1];

    for(int i = 2; i < maxn; i++) {
        int x = i;
        while(x != 1) {
            int d = sieve[x];
            dp[i] = max(dp[i], dp[i / d] + cnt[i]);
            while(x % d == 0) x /= d;
        }

        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";

    return 0;
}


