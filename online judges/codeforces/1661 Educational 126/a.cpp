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
        ll a[n], b[n];

        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++)
            cin >> b[i];

        ll dp[n][2];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 1; i < n; i++) {
            int add1 = abs(a[i]-a[i-1]) + abs(b[i]-b[i-1]);
            int add2 = abs(a[i]-b[i-1]) + abs(b[i]-a[i-1]);

            dp[i][0] = min(dp[i-1][0] + add1, dp[i-1][1] + add2);
            dp[i][1] = min(dp[i-1][0] + add2, dp[i-1][1] + add1);
        }

        cout << min(dp[n-1][0], dp[n-1][1]) << "\n";
    }
	
	
	return 0;
}

