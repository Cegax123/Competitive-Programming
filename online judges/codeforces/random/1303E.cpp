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
    int t; cin >> t;
    while(t--) {
        string s, t; cin >> s >> t;
        
        s = "." + s;
        t = "." + t;

        int n = s.size(), m = t.size();

        int dp[n+1][m+1][n+1];

        memset(dp, -1, sizeof(dp));

        for(int i = 1; i <= n; i++)
            dp[0][0][i] = 0;

        bool found = false;

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                for(int k = 1; k <= n; k++) {
                    dp[i][j][k] = dp[i-1][j][k];

                    int pos = k + dp[i][j][k];

                    if(pos <= m and dp[i][j][k] >= 0 and s[i] == t[pos]) dp[i][j][k]++;

                    if(j and s[i] == t[j]) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k]);
                    }

                    if(j >= k-1 and dp[i][j][k] + k > m) found = true;
                }
            }
        }

        cout << (found ? "YES\n" : "NO\n");

    }

	
    return 0;
}


