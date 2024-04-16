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

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;

    int d[n][n];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            d[i][j] = INF;

    for(int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;

        d[u][v] = min(d[u][v], w);
    }
    
    int dp[n][1 << n];

    for(int i = 0; i < n; i++) 
        for(int j = 0; j < (1 << n); j++) dp[i][j] = INF;

    dp[0][1] = 0;

    for(int mask = 1; mask < (1 << n); mask++) {
        for(int i = 0; i < n; i++) {
            if(((mask >> i)&1) == 0) continue;

            for(int j = 0; j < n; j++) {
                if(i == j or ((mask >> j)&1) == 0) continue;

                dp[i][mask] = min(dp[i][mask], dp[j][mask ^ (1 << i)] + d[j][i]);
            }
        }
    }

    int ans = INF;

    for(int i = 0; i < n; i++)
        ans = min(ans, dp[i][(1 << n)-1] + d[i][0]);

    cout << (ans == INF ? -1 : ans) << "\n";
	
    return 0;
}


