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
	int n, m; cin >> n >> m;

    int a[n][m];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
	
    int dp[n][m];
    dp[0][0] = a[0][0];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 and j == 0) continue;
            if(i == 0) dp[i][j] = dp[i][j-1] + a[i][j];
            else if(j == 0) dp[i][j] = dp[i-1][j] + a[i][j];
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]) + a[i][j];
        }
    }

    cout << dp[n-1][m-1] << "\n";
	
	return 0;
}

