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
    int n, c; cin >> n >> c;
    vi dp(c+1, -1);
    dp[0] = 0;

    for(int i = 0; i < n; i++) {
        int v, w; cin >> v >> w;
        vi ndp(c+1, -1);

        for(int j = 0; j <= c; j++) {
            if(dp[j] >= 0 and j + w <= c) {
                ndp[j + w] = max(ndp[j + w], dp[j] + v);
            }
        }

        for(int j = 0; j <= c; j++) 
            dp[j] = max(dp[j], ndp[j]);
    }

    int ans = 0;

    for(int i = 0; i <= c; i++) ans = max(ans, dp[i]);

    cout << ans << "\n";

    return 0;
}


