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

ll ceil(ll x, ll y) {
    return (x+y-1)/y;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;
    ll t[n+1], x[n+1], y[n+1];

    for(int i = 1; i <= n; i++)
        cin >> t[i] >> x[i] >> y[i];

    vi dp(m+1, -1);
    dp[0] = 0;

    const ll div = 1e5;

    for(int i = 1; i <= n; i++) {
        vi ndp = dp;
        
        for(int j = 0; j <= m; j++) {
            if(dp[j] == -1) continue;
            
            ll tmp = j;
            for(int k = 0; k < y[i]; k++) {
                ll nxt;

                if(t[i] == 1) nxt = tmp + ceil(x[i], div);
                else nxt = ceil(tmp * x[i], div);

                if(nxt > m) break;
                if(dp[nxt] != -1) break;

                ndp[nxt] = i;
                tmp = nxt;
            }
        }

        dp = ndp;
    }

    for(int i = 1; i <= m; i++)
        cout << dp[i] << " ";
	
    return 0;
}


