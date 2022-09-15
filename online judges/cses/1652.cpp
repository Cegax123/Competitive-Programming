#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define pb push_back 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
 
 
int main() {
	std::ios::sync_with_stdio(false); cin.tie(NULL);
	int n, q; cin >> n >> q;
 
    char board[n+5][n+5];
 
    for(int i = 0; i < n; i++)
        cin >> board[i];
 
    int dp[n+5][n+5];
 
    if(board[0][0] == '*') dp[0][0] = 1;
 
    for(int i = 1; i < n; i++) {
        dp[i][0] = dp[i-1][0];
        if(board[i][0] == '*') dp[i][0]++;
 
        dp[0][i] = dp[0][i-1];
        if(board[0][i] == '*') dp[0][i]++;
    }
 
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            if(board[i][j] == '*') dp[i][j]++;
        }
    }
 
    while(q--) {
        int a,b,x,y; cin >> a >> b >> x >> y;
 
        a--; b--; x--; y--;
 
        int ans = dp[x][y];
 
        if(a) ans -= dp[a-1][y];
        if(b) ans -= dp[x][b-1];
        if(a and b) ans += dp[a-1][b-1];
 
        cout << ans << "\n";
    }
		
	return 0;
}
