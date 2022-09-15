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

    const int maxt = 1e5;
    int add[maxt+5][5];
    memset(add, 0, sizeof(add));

    for(int i = 0; i < n; i++) {
        int t, x; cin >> t >> x;
        int a; cin >> a;
        add[t][x] = a;
    }

    ll dp[maxt+5][5];

    memset(dp, -1, sizeof(dp));

    dp[0][0] = 0;

    for(int i = 0; i <= maxt; i++) {
        for(int x = 0; x < 5; x++) {
            if(dp[i][x] == -1) continue;
            dp[i+1][x] = max(dp[i+1][x], dp[i][x] + add[i+1][x]);
            if(x+1 < 5) dp[i+1][x+1] = max(dp[i+1][x+1], dp[i][x] + add[i+1][x+1]);
            if(x) dp[i+1][x-1] = max(dp[i+1][x-1], dp[i][x] + add[i+1][x-1]);
        }
    }

    ll ans = 0;

    for(int i = 0; i < 5; i++)
        ans = max(ans, dp[maxt][i]);

    cout << ans << "\n";
	
    return 0;
}


