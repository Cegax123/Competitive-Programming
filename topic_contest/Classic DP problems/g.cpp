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

const int maxv = 100 * 100 + 5;
const int INF = 1e9+5;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, c; cin >> n >> c;

    vi dp(maxv, INF);
    dp[0] = 0;

    for(int i = 0; i < n; i++) {
        int v, w; cin >> v >> w;

        vi ndp(maxv, INF);

        for(int j = 0; j < maxv; j++) {
            if(j + v < maxv) ndp[j+v] = min(ndp[j+v], dp[j] + w);
        }

        for(int j = 0; j < maxv; j++)
            dp[j] = min(dp[j], ndp[j]);
    }

    int ans = 0;
    for(int j = 0; j < maxv; j++) {
        if(dp[j] <= c) ans = j;
    }

    cout << ans << "\n";
	
    return 0;
}


