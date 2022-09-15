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

ll const mod = 998244353;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, K; cin >> n >> K;

    int p[n], q[n];

    for(int i = 0; i < n; i++)
        cin >> p[i];
	
    for(int i = 0; i < n; i++)
        cin >> q[i];

    int v[n+1];

    for(int i = 0; i < n; i++) {
        v[p[i]] = q[i];
        v[p[i]]--;
    }

    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    
    dp[0][n] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = n-1; j >= 0; j--) {
            for(int k = 1; k <= n; k++) {
                if(v[i+1] < k) 
                    dp[j+1][v[i+1]] = (dp[j+1][v[i+1]] + dp[j][k]) % mod;
            }
        }
    }

    int ans = 0;

    for(int k = 0; k < n; k++) {
        cout << dp[K][k] << endl;
        ans = (ans + dp[K][k]) % mod;
    }

    cout << ans << "\n";
	
	return 0;
}

