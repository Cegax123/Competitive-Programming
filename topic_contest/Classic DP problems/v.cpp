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

    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    ll dp[n][n];

    for(int i = 0; i < n; i++) dp[i][i] = a[i];

    for(int len = 2; len <= n; len++) {
        for(int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
        }
    }
	
    cout << dp[0][n-1] << "\n";

    return 0;
}


