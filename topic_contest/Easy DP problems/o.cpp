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

    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int dp[k+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for(int j = 0; j < n; j++) {
        for(int i = k; i >= a[j]; i--) {
            dp[i] = (dp[i] + dp[i-a[j]]) % mod;
        }
    }

    cout << dp[k] << "\n";
	
    return 0;
}


