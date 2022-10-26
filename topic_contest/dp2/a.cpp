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

ll sum(ll a, ll b) {return (a+b)%mod;}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int R, G; cin >> R >> G;

	vi dp(R+1, 0);
    dp[R] = 1;

    for(int t = 1; t <= 900; t++) {
        bool cmp = 0;
        vi ndp(R+1, 0);

        for(int r = 0; r <= R; r++) {
            int g = G - (t * (t+1) / 2 - (R - r));
            if(g < 0) continue;

            cmp = 1;
            ndp[r] = dp[r];
            if(r + t <= R) ndp[r] = sum(ndp[r], dp[r+t]);
        }

        if(!cmp) break;
        dp = ndp;
    }

    ll ans = 0;

    for(int i = 0; i <= R; i++)
        ans = sum(ans, dp[i]);

    cout << ans << "\n";
	
	return 0;
}

