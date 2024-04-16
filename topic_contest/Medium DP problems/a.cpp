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

const int maxh = 900; 
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int r, g; cin >> r >> g;
    vi dp(maxn, 0), poss(maxn, 0);

    dp[0] = poss[0] = 1;
    int ans = 1;
	
    for(int h = 1; h <= maxh; h++) {
        vi ndp(maxn, 0), nposs(maxn, 0);

        // insert red
        for(int i = h; i <= r; i++) {
            ndp[i] += dp[i-h];
            if(ndp[i] >= mod) ndp[i] -= mod;

            if(poss[i-h]) nposs[i] = 1;
        }

        // insert green 

        for(int i = 0; i <= r; i++) {
            int G = h * (h + 1) / 2 - i;
            if(G <= g) {
                ndp[i] += dp[i];
                if(ndp[i] >= mod) ndp[i] -= mod;

                if(poss[i]) nposs[i] = 1;
            }
        }

        bool is_poss = 0;
        for(int i = 0; i < maxn; i++) {
            if(nposs[i]) is_poss = 1;
        }

        if(!is_poss) break;

        ans = 0;
        for(int i = 0; i < maxn; i++) {
            ans += ndp[i];
            if(ans > mod) ans -= mod;
        }

        dp = ndp;
        poss = nposs;
    }

    cout << ans << "\n";

    return 0;
}


