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

const int maxn = 1005;

int n;
int a[maxn];

int dp[maxn][maxn];
ii nxt[maxn][maxn], mov[maxn][maxn];

int solve(int pos, int lft) {
    if(pos == n+1) {
        return 0;
    }

    if(dp[pos][lft] != -1) return dp[pos][lft];

    if(lft == n+1) {
        mov[pos][lft] = {pos, -1};
        nxt[pos][lft] = {n+1, n+1};
        return dp[pos][lft] = a[pos];
    }
    mov[pos][lft] = {pos, lft};
    nxt[pos][lft] = {lft+1, lft+2};
    dp[pos][lft] = max(a[pos], a[lft]) + solve(lft+1, lft+2);

    if(lft+1 <= n) {
        if(dp[pos][lft] > max(a[pos], a[lft+1]) + solve(lft, lft+2)) {
            mov[pos][lft] = {pos, lft+1};
            nxt[pos][lft] = {lft, lft+2};
            dp[pos][lft] = max(a[pos], a[lft+1]) + dp[lft][lft+2];
        }
        if(dp[pos][lft] > max(a[lft], a[lft+1]) + solve(pos, lft+2)) {
            mov[pos][lft] = {lft, lft+1};
            nxt[pos][lft] = {pos, lft+2};
            dp[pos][lft] = max(a[lft], a[lft+1]) + dp[pos][lft+2];
        }
    }

    return dp[pos][lft];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(dp, -1, sizeof(dp));
    memset(nxt, -1, sizeof(nxt));
    memset(mov, -1, sizeof(mov));


    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    cout << solve(1, 2) << "\n";

    int x = 1, y = 2;

    while(x != n+1) {
        cout << mov[x][y].first << " ";
        if(mov[x][y].second != -1) cout << mov[x][y].second;
        cout << "\n";

        int nx = nxt[x][y].first, ny = nxt[x][y].second;
        x = nx; y = ny;
    }

    return 0;
}


