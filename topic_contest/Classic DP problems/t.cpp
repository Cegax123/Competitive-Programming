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
    int h, w; cin >> h >> w;

    string b[h];
    for(int i = 0; i < h; i++) cin >> b[i];

    const int mod = 1e9 + 7;

    int dp[h][w];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if((i == 0 and j == 0) or b[i][j] == '#') continue;
            if(i) dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
            if(j) dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
        }
    }

    cout << dp[h-1][w-1] << "\n";
	
    return 0;
}


