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

const ll mod = 1e9 + 7;

void sum(ll &x, ll y)
{
	x+=y;
	if(x>=ll(5e18)) x%=mod;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, T; cin >> n >> T;
    int t[n];

    for(int i = 1; i <= n; i++) cin >> t[i];

    string s; cin >> s;

    ll dp[2][n+5][T+5][2];
    memset(dp, 0, sizeof(dp));

    dp[0][0][0][0] = 1;

    for(int i = 0; i < n; i++) {
        int nxt = 1-(i&1);

        for(int comp = 0; comp <= n; comp++)
            for(int curr = 0; curr <= T; curr++)
                for(int has_start = 0; has_start <= 1; has_start++)
                    dp[nxt][comp][curr][has_start] = 0;

        for(int comp = 0; comp <= i; comp++) {
            for(int curr = 0; curr <= T; curr++) {
                for(int has_start = 0; has_start <= 1; has_start++) {

                    ll currdp = dp[i&1][comp][curr][has_start] % mod;
                    ll newcurr = min((ll) T+1, (ll) curr + t[i+1]);

                    if(s[i] == 'G') {
                        // merge component
                        if(comp-1 >= 1) sum(dp[nxt][comp-1][newcurr][has_start], currdp * (comp-1));

                        // end of component
                        sum(dp[nxt][comp][newcurr][has_start], currdp * comp);

                        // add to start
                        
                        if(!has_start) {
                            // new component
                            sum(dp[nxt][comp+1][newcurr][1], currdp);

                            // start first component
                            sum(dp[nxt][comp][newcurr][1], currdp);
                        }
                    }
                    else if(s[i] == 'B') {
                        // new component
                        sum(dp[nxt][comp+1][newcurr][has_start], currdp * (comp+1-has_start));
                        
                        // start of component
                        sum(dp[nxt][comp][newcurr][has_start], currdp * (comp-has_start));
                    }
                    else {
                        // new component
                        sum(dp[nxt][comp+1][newcurr][has_start], currdp * (comp+1-has_start));

                        if(!has_start) sum(dp[nxt][comp+1][newcurr][1], currdp);

                        // merge component
                        if(comp-1 >= 1) sum(dp[nxt][comp-1][newcurr][has_start], currdp * (comp-1));

                        // end of component
                        sum(dp[nxt][comp][newcurr][has_start], currdp * (comp));

                        // start of component
                        sum(dp[nxt][comp][newcurr][has_start], currdp * (comp-has_start));

                        if(!has_start) sum(dp[nxt][comp][newcurr][1], currdp);

                        // ignore element
                        sum(dp[nxt][comp][curr][has_start], currdp);
                    }
                }
            }
        }
    }

    for(int i = 1; i <= T; i++)
        cout << dp[n&1][1][i][1] % mod << " ";
	
    return 0;
}



