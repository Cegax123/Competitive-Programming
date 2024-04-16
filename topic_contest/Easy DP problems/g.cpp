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

    int n, k; cin >> n >> k;
    int dp[n+1];
    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        dp[i] = 0;
        for(int j = 1; j <= k; j++) {
            if(i-j >= 1) dp[i] = (dp[i] + dp[i-j]) % mod;
        }
    }

    cout << dp[n] << "\n";
	
    return 0;
}


