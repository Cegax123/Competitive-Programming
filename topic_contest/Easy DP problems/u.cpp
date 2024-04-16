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
    int n; cin >> n;

    ll dp[n+1];
    dp[0] = 1;

    ll sum[n+1];
    sum[0] = 1;

    for(int i = 1; i <= n; i++) {
        if(i == 1) {
            dp[i] = 1;
            sum[i] = 2;
            continue;
        }
        if(i == 2) {
            dp[i] = 2;
            sum[i] = 4;
            continue;
        }

        dp[i] = 0;
        if(i >= 2) dp[i] = dp[i] + sum[i-2];
        if(i >= 3) dp[i] = dp[i] + sum[i-3];

        sum[i] = dp[i] + sum[i-1];
    }

    cout << sum[n] << "\n";
	
    return 0;
}


