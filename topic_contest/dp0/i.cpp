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
	int n, w; cin >> n >> w;

    int v[n+1], c[n+1], m[n+1];

    for(int i = 1; i <= n; i++) 
        cin >> v[i] >> c[i] >> m[i];
    

    int dp[n+1][w+1];
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= w; j++) {
            for(int k = 0; k <= m[i]; k++) {
                if(k * c[i] <= j) dp[i][j] = max(dp[i][j], dp[i-1][j - k * c[i]] + k * v[i]);
            }
        }
    }

    cout << dp[n][w] << "\n";
	
	return 0;
}

