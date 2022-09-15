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

const ll mod = 1e9+7;

ll sum(ll a, ll b) {
    return (a+b)%mod;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, m; cin >> n >> m;
    int a[n][m];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
	
    int dp[n][m];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i+a[i][j] < n) dp[i+a[i][j]][j] = sum(dp[i+a[i][j]][j], dp[i][j]);
            if(j+a[i][j] < m) dp[i][j+a[i][j]] = sum(dp[i][j+a[i][j]], dp[i][j]);
        }
    }

    cout << dp[n-1][m-1] << "\n";
	
	return 0;
}

