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
    ll a[n+1];

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    ll sum[n+1];

    sum[0] = 0;
    for(int i = 1; i <= n; i++) 
        sum[i] = sum[i-1] + a[i];
	
    ll dp[n+1][n+1];
    
    for(int i = 1; i <= n; i++)
        dp[i][i] = a[i];

    for(int l = 2; l <= n; l++) {
        for(int i = 1; i+l-1 <= n; i++) {
            int j = i+l-1;

            dp[i][j] = max(a[i]+(sum[j]-sum[i]-dp[i+1][j]), a[j]+(sum[j-1]-sum[i-1]-dp[i][j-1]));
        }
    }

    cout << dp[1][n] << "\n";
	
	return 0;
}

