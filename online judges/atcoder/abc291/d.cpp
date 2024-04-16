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
    const ll mod = 998244353;
    int n; cin >> n;
    int a[n], b[n];

    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];

    ll dp[n][2];

    dp[0][0] = dp[0][1] = 1;


    for(int i = 1; i < n; i++) {
        if(a[i] == a[i-1] and a[i] == b[i-1]) dp[i][0] = 0;
        else if(a[i] == a[i-1]) dp[i][0] = dp[i-1][1];
        else if(a[i] == b[i-1]) dp[i][0] = dp[i-1][0];
        else dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % mod;

        if(b[i] == a[i-1] and b[i] == b[i-1]) dp[i][1] = 0;
        else if(b[i] == a[i-1]) dp[i][1] = dp[i-1][1];
        else if(b[i] == b[i-1]) dp[i][1] = dp[i-1][0];
        else dp[i][1] = (dp[i-1][0] + dp[i-1][1]) % mod;
    }

    cout << (dp[n-1][0] + dp[n-1][1]) % mod << "\n";
	
    return 0;
}


