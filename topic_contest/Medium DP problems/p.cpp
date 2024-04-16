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

const int maxn = 50;
int dp[maxn][maxn][maxn][maxn];
string board[maxn];
const int INF = 1e9;

int solve(int a, int b, int c, int d) {
    if(dp[a][b][c][d] != -1) return dp[a][b][c][d];

    if(a == c and b == d) return board[a][b] == '#';

    int ans = INF;
    for(int i = b; i < d; i++)
        ans = min(ans, solve(a, b, c, i) + solve(a, i+1, c, d));

    for(int i = a; i < c; i++)
        ans = min(ans, solve(a, b, i, d) + solve(i+1, b, c, d));

    return dp[a][b][c][d] = min(ans, max(c-a+1, d-b+1));
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> board[i];

    memset(dp, -1, sizeof(dp));

    cout << solve(0, 0, n-1, n-1) << "\n";
	
    return 0;
}


