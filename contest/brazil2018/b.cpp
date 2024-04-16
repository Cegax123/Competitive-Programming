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
    const int maxn = 105;
    int dp[maxn][maxn];

    dp[0][0] = 0;

    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxn; j++) {
            if(i == 0 and j == 0) continue;
            
            vi cnt(305, 0);

            for(int k = 0; k < i; k++) {
                if(dp[k][j] < 305) cnt[dp[k][j]] = 1;
            }

            for(int k = 0; k < j; k++) {
                if(dp[i][k] < 305) cnt[dp[i][k]] = 1;
            }

            for(int k = 1; k <= min(i, j); k++)
                if(dp[i-k][j-k] < 305) cnt[dp[i-k][j-k]] = 1;

            for(int k = 0; k < 305; k++) {
                if(cnt[k] == 0) {
                    dp[i][j] = k;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }

    int n; cin >> n;
    int x = 0;

    while(n--) {
        int u, v; cin >> u >> v;
        x ^= dp[u][v];
    }

    if(x == 0) cout << "N\n";
    else cout << "Y\n";
	
    return 0;
}


