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

const int maxX = 50+5;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, a; cin >> n >> a;
    int x[n];
    for(int i = 0; i < n; i++) cin >> x[i];

    ll dp[2][maxX * maxX][maxX];
    memset(dp, 0, sizeof(dp));

    int ans = 0;

    dp[0][x[0]][1] = 1;

    if(x[0] == a) ans++;

    for(int i = 1; i < n; i++) {
        dp[i&1][x[i]][1] = 1;
        for(int j = x[i]; j < maxX * maxX; j++) {
            for(int k = 2; k < maxX; k++) {
                dp[i&1][j][k] += dp[1-(i&1)][j-x[i]][k-1];
            }
        }

        for(int j = x[i]; j < maxX * maxX; j++) {
            for(int k = 2; k < maxX; k++) {
                if(j == a * k) ans += dp[i&1][j][k];
            }
        }
    }

    //int ans = 0;
    //for(int i = 0; i < n; i++) {
        //for(int j = 0; j < maxX * maxX; j++) {
            //for(int k = 1; k < maxX; k++) {
                //if(j == k * a) ans += dp[i&1][j][k];
            //}
        //}
    //}

    cout << ans << "\n";
	
    return 0;
}


