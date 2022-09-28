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

vector<int> z_function(const string& s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q; cin >> q;
    while(q--) {
        string s, t; cin >> s >> t;
        
        string tmp = t + "#" + s;

        vi z = z_function(tmp);

        vi a(s.size()+1, 0);
        for(int i = t.size()+1; i < (int) tmp.size(); i++)
            if(z[i] == (int) t.size()) a[i-t.size()] = 1;

        int L = t.size();
        const int mod = 1e9+7;

        auto sum = [&](int a, int b) {
            return (a+b)%mod;
        };

        int n = s.size();
        int dp[n+1][n+1];

        memset(dp, -1, sizeof(dp));
        dp[0][0] = 1;

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                if(a[i] == 0) {
                    dp[i][j] = dp[i-1][j];
                }
                else if(j != 0) {
                    for(int k = max(0, i+1-L); k <= i; k++) {
                        if(a[k] == 0) continue;
                        int add = dp[max(k-L, 0)][j-1];

                        if(add != -1) {
                            if(dp[i][j] == -1) dp[i][j] = 0;
                            dp[i][j] = sum(dp[i][j], add);
                        }
                    }
                }
            }
        }

        dp[n][0] = 1;

        int ans = 0;
        for(int i = 1; i <= n; i++)
            if(dp[n][i] != -1) {
                ans = i;
                break;
            }

        cout << ans << " " << dp[n][ans] << "\n";
    }

	
    return 0;
}


