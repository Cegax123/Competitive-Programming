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
    const int maxsum = 1e4 + 5;
    const int mod = 1e9 + 7;

    vi dp(2 * maxsum + 100, 0);
    
    int ans = 0;

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;

        dp[maxsum] = (dp[maxsum] + 1) % mod;
        vi ndp(2 * maxsum + 100, 0);

        for(int j = 0; j < 2 * maxsum + 100; j++) {
            if(j + a < 2 * maxsum + 100) ndp[j] = (ndp[j] + dp[a + j]) % mod;
            if(j - a >= 0) ndp[j] = (ndp[j] + dp[j - a]) % mod;
        }

        dp = ndp;

        //for(int j = -4; j <= 4; j++)
            //cout << dp[maxsum + j] << " ";
        //cout << endl;

        ans = (ans + dp[maxsum]) % mod;
    }

    cout << ans << "\n";
	
    return 0;
}


