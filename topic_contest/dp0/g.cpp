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

const int INF = 1e9+1;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, w; cin >> n >> w;
    int v[n+1], c[n+1];

    for(int i = 1; i <= n; i++)
        cin >> v[i] >> c[i];
	
    vector<vi> dp(n+1, vi(n*100+1, INF));

    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n * 100; j++) {
            dp[i][j] = dp[i-1][j];
            if(v[i] <= j) dp[i][j] = min(dp[i][j], dp[i-1][j-v[i]]+c[i]);
        }
    }

    int ans = 0;

    for(int i = 0; i <= n*100; i++)
        if(dp[n][i] <= w) ans = i;

    cout << ans << "\n";
	
	return 0;
}

