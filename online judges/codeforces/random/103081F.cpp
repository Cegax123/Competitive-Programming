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
    int r, n, m; cin >> r >> n >> m;

    ll dp[n+5][n+5];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            if(i == r) {
                // new component
                dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % m;
            }
            else {
                // new component
                dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % m;

                // 1 son
                dp[i][j] = (dp[i][j] + dp[i-1][j] * j) % m;

                // 2 son
                dp[i][j] = (dp[i][j] + dp[i-1][j+1] * ((j+1) * j / 2)) % m;
            }
        }
    }

    //for(int i = 1; i <= n; i++) {
        //for(int j = 1; j <= i; j++) {
            //cout << dp[i][j] << " ";
        //}
        //cout << "\n";
    //}

    cout << dp[n][1] << "\n";
	
    return 0;
}



