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

const int maxv = 500;
const int INF = 1e8;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    vector<vi> dp(maxv+5, vi(maxv+5, INF));
	
    for(int i = 1; i <= maxv; i++)
        dp[i][i] = 0;

    for(int i = 1; i <= maxv; i++) {
        for(int j = 1; j <= maxv; j++) {
            if(i == j) continue;

            for(int x = 1; x < i; x++) 
                dp[i][j] = min(dp[i][j], dp[x][j]+dp[i-x][j]+1);
            
            for(int x = 1; x < j; x++) 
                dp[i][j] = min(dp[i][j], dp[i][x]+dp[i][j-x]+1);
        }
    }

    int a, b; cin >> a >> b;

    cout << dp[a][b] << "\n";
	
	return 0;
}

