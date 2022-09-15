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
	string s, t; cin >> s >> t;

    int n = s.size(), m = t.size();

    int dp[n+1][m+1];

    dp[0][0] = 0;

    for(int i = 1; i <= n; i++)
        dp[i][0] = i;

    for(int i = 1; i <= m; i++)
        dp[0][i] = i;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min({dp[i-1][j-1]+1, dp[i-1][j]+1, dp[i][j-1]+1});
        }
    }

    cout << dp[n][m] << "\n";
	
	return 0;
}

