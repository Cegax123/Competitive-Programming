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
    ll k; cin >> k;
    string s; cin >> s;

    s = "." + s;

    ll dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));

    const ll INF = 1e15;

    dp[0][0] = 1;

    const int E = 26;
    vi last(E, -1);

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= n; j++)
            dp[i][j] = dp[i-1][j];

        int c = s[i]-'a';
        for(int j = 1; j <= i; j++) {
            dp[i][j] = min(INF, dp[i][j] + dp[i-1][j-1]);
            if(last[c] != -1) {
                dp[i][j] -= dp[last[c]-1][j-1];
                dp[i][j] = max(dp[i][j], 0ll);
            }
        }

        last[c] = i;
    }

    ll cost = 0;
    for(int i = n; i >= 0; i--) {
        if(k <= dp[n][i]) {
            cost += k * (n-i);
             k = 0;
        }
        else {
            cost += dp[n][i] * (n-i);
            k -= dp[n][i];
        }
    }

    if(k) cout << -1 << "\n";
    else cout << cost << "\n";
	
    return 0;
}


