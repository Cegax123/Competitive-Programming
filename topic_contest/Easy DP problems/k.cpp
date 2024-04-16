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
    int n, a, b, c; cin >> n >> a >> b >> c;

    int dp[n+1];
    for(int i = 0; i <= n; i++) dp[i] = -1e9;

    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        if(i >= a) dp[i] = max(dp[i], dp[i-a] + 1);
        if(i >= b) dp[i] = max(dp[i], dp[i-b] + 1);
        if(i >= c) dp[i] = max(dp[i], dp[i-c] + 1);
    }

    cout << dp[n] << "\n";
	
    return 0;
}


