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
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n+1], b[n+1];

        for(int i = 1; i <= n; i++) 
            cin >> a[i];
        
        for(int i = 1; i <= n; i++) 
            cin >> b[i];

        int total = 0;
        
        for(int i = 1; i <= n; i++)
            total += a[i] + b[i];

        int dp[n+1][n * 100+1];
        memset(dp, 0, sizeof(dp));

        dp[0][0] = 1;

        int pa[n+1][n * 100+1];

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= n*100; j++) {
                if(dp[i-1][j] and j+a[i] <= n*100) {
                    dp[i][j+a[i]] = 1; 
                    pa[i][j+a[i]] = 0;
                }
                if(dp[i-1][j] and j+b[i] <= n*100) {
                    dp[i][j+b[i]] = 1;
                    pa[i][j+b[i]] = 1;
                }
            }
        }

        int ans = (int) 1e9;
        int ind = 0;

        for(int j = 1; j <= n*100; j++) {
            if(dp[n][j]) {
                if(ans > j * j + (total-j) * (total - j)) {
                    ind = j;
                    ans = j * j + (total-j) * (total - j);
                }
            }
        }
        
        int k = n;
        vector<ll> c, d;

        while(k) {
            int x = pa[k][ind];
            if(x == 0) {
                c.pb(a[k]);
                d.pb(b[k]);
                ind -= a[k];
            }
            else {
                c.pb(b[k]);
                d.pb(a[k]);
                ind -= b[k];
            }
            k--;
        }

        reverse(all(c));
        reverse(all(d));

        ll res = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                res += (c[i]+c[j]) * (c[i]+c[j]);
                res += (d[i]+d[j]) * (d[i]+d[j]);
            }
        }

        cout << res << "\n";
    }

	return 0;
}

