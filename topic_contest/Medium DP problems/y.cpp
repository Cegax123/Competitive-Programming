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
    int n, m; cin >> n >> m;
    vii end[n+2];
    
    for(int i = 0; i < m; i++) {
        int l, r, x; cin >> l >> r >> x;
        end[r+1].pb({l+1, x});
    }

    for(auto e : end[2]) {
        if(e.second > 1) {
            cout << 0 << "\n";
            return 0;
        }
    }

    const int mod = 1e9 + 7;

    vector<vi> dp(n+2, vi(n+2, 0));

    dp[1][0] = 1;
    
    for(int i = 2; i <= n; i++) {
        vector<vi> ndp(n+2, vi(n+2, 0));

        for(int j = 0; j <= i-1; j++) {
            for(int k = 0; k <= j-1; k++) {
                ndp[j][k] = (ndp[j][k] + dp[j][k]) % mod;
                ndp[i][k] = (ndp[i][k] + dp[j][k]) % mod;
                ndp[i][j] = (ndp[i][j] + dp[j][k]) % mod;
            }
        }

        for(auto& e : end[i+1]) {
            if(e.second == 1) {
                for(int j = 0; j <= i; j++) {
                    for(int k = 0; k <= j-1; k++) {
                        if(j >= e.first) ndp[j][k] = 0;
                    }
                }
            }
            else if(e.second == 2) {
                for(int j = 0; j <= i; j++) {
                    for(int k = 0; k <= j-1; k++) {
                        if(j < e.first or k >= e.first) ndp[j][k] = 0;
                    }
                }
            }
            else {
                for(int j = 0; j <= i; j++) {
                    for(int k = 0; k <= j-1; k++) {
                        if(k < e.first) ndp[j][k] = 0;
                    }
                }
            }
        }

        dp = ndp;
    }

    int ans = 0;

    for(int i = 0; i <= n+1; i++) {
        for(int j = 0; j <= i-1; j++) {
            ans = (ans + dp[i][j]) % mod;
        }
    }

    cout << (ans * 1ll * 3) % mod << "\n";
	
    return 0;
}


