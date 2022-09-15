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

int n, m;

ll add(ll a, ll b) {
    return (a+b)%m;
}

ll mul(ll a, ll b) {
    return a * b % m;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;

    int dp[n+5][n+5];
    memset(dp, 0, sizeof(dp));

    dp[1][1] = 1;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            // new component
            dp[i+1][j+1] = add(dp[i+1][j+1], mul(dp[i][j], j+1));

            // add to component 0()
            dp[i+1][j] = add(dp[i+1][j], mul(dp[i][j], 2 * j));

            // add to component 00()
            dp[i+2][j] = add(dp[i+2][j], mul(dp[i][j], 2 * j));

            // merge component () 00 ()
            dp[i+2][j-1] = add(dp[i+2][j-1], mul(dp[i][j], 2 * (j-1)));

            // merge component () 000 ()
            dp[i+3][j-1] = add(dp[i+3][j-1], mul(dp[i][j], j-1));
        }
    }

    cout << dp[n][1] << "\n";
	
    return 0;
}


