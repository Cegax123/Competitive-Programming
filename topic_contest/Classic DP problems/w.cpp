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

const int mod = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k; cin >> n >> k;

    vi dp(k+1, 0);
    dp[0] = 1;

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        int sum = 0;

        vi ndp(k+1, 0);
        
        for(int j = 0; j <= k; j++) {
            sum = (sum + dp[j]) % mod;
            if(j - a - 1 >= 0) {
                sum = (sum - dp[j-a-1]) % mod;
                if(sum < 0) sum += mod;
            }
            
            ndp[j] = sum;
        }

        dp = ndp;
    }

    cout << dp[k] << "\n";
	
    return 0;
}


