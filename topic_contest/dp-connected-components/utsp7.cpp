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
    int n; cin >> n;

    const int b = 30;

    auto  msb = [](int x) {
        for(int i = b; i >= 0; i--) {
            if((x >> i)&1) return i;
        }
        return 0;
    };

    vi a(n+1, 0);
    for(int i = 1; i <= n; i++) 
        cin >> a[i];

    sort(all(a));

    int msba[n+1];
    memset(msba, 0, sizeof(msba));

    for(int i = 1; i <= n; i++)
        msba[i] = msb(a[i]);

    ll dp[2][n+1][n+1][3];

    // 0 : last_msb == msba[i]
    // 1 : last_msb + 1 == msba[i]
    // 2 : last_msb + 1 < msba[i]

    memset(dp, 0, sizeof(dp));

    dp[1][1][0][0] = 1;
    const int mod = 1e9 + 7;

    auto sum = [&](ll& a, ll b) {
        a = (a + b) % mod;
    };

    for(int i = 1; i < n; i++) {
        int nxt = 1-(i&1);

        for(ll comp = 1; comp <= n; comp++)
            for(int cnt_right = 0; cnt_right <= n; cnt_right++)
                for(int last_status = 0; last_status < 3; last_status++)
                    dp[nxt][comp][cnt_right][last_status] = 0;

        for(ll comp = 1; comp <= i; comp++) {
            for(int cnt_right = 0; cnt_right < comp; cnt_right++) {
                for(int diff_last = 0; diff_last < 3; diff_last++) {
                    ll curr = dp[i&1][comp][cnt_right][diff_last];

                    int curr_cnt = cnt_right;
                    if(msba[i+1] != msba[i]) curr_cnt = 0;

                    if(msba[i+1] == msba[i] or (msba[i] + 1 == msba[i+1] and cnt_right + 1 == comp) or (msba[i] + 1 < msba[i+1] and comp == 1)) {
                        int nxt_diff_last = min(2, diff_last + (msba[i+1]-msba[i]));

                        // new component after last component
                        if(nxt_diff_last == 1) sum(dp[nxt][comp+1][curr_cnt][0], curr);
                        else if(nxt_diff_last == 0) sum(dp[nxt][comp+1][curr_cnt+1][0], curr);

                        // new component other components
                        sum(dp[nxt][comp+1][curr_cnt+1][nxt_diff_last], comp * curr);

                        // merge
                        ll places = comp-1-curr_cnt;
                        if(places > 0) sum(dp[nxt][comp-1][curr_cnt][nxt_diff_last], places * curr);
                            
                        // add to start component
                        sum(dp[nxt][comp][curr_cnt][nxt_diff_last], comp * curr);

                        // add to end component except last component
                        if(places > 0) sum(dp[nxt][comp][curr_cnt+1][nxt_diff_last], places * curr);

                        // add to end component in last component
                        if(nxt_diff_last == 1) sum(dp[nxt][comp][curr_cnt][0], curr);
                    }
                }
            }
        }
    }

    ll ans = 0;

    for(int last_status = 0; last_status < 3; last_status++)
        sum(ans, dp[n&1][1][0][last_status]);

    cout << ans << "\n";

    return 0;
}
