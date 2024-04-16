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
    const int mod = 1e9 + 7;
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int n = s.size();

        int dp[n+1];

        const int E = 26;

        int last[E];
        memset(last, -1, sizeof(last));

        dp[0] = 1;

        for(int i = 1; i <= n; i++) {
            int c = s[i-1]-'A';

            dp[i] = (2 * dp[i-1]) % mod;

            if(last[c] != -1) {
                dp[i] = (dp[i] - dp[last[c]-1]) % mod;
                if(dp[i] < 0) dp[i] += mod;
            }

            last[c] = i;
        }

        cout << dp[n] << "\n";
    }

	
    return 0;
}


