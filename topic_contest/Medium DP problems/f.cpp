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
    int A[n][n];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> A[i][j];

    const int INF = 1e9;

    int dx[] = {-1, 0};
    int dy[] = {0, -1};

    auto is_valid = [&](int x, int y) {
        return x >= 0 and x < n and y >= 0 and y < n;
    };


    vector<vi> dp(1, vi(1, A[0][0]));

    for(int i = 1; i <= 2 * n - 2; i++) {
        int len = (i < n ? i + 1 : 2 * n - i - 1);
        vector<vi> ndp(len, vi(len, -INF));

        int stx = min(n-1, i), sty = (i < n ? 0 : i + 1 - n);

        for(int j = 0; j < len; j++) {
            for(int k = 0; k < len; k++) {

                int jx = stx - j, jy = sty + j;
                int kx = stx - k, ky = sty + k;

                int off = (jx == kx ? -A[jx][jy] : 0);

                for(int a = 0; a < 2; a++) {
                    for(int b = 0; b < 2; b++) {
                        int bjx = jx + dx[a], bjy = jy + dy[a];
                        int bkx = kx + dx[b], bky = ky + dy[b];

                        if(is_valid(bjx, bjy) and is_valid(bkx, bky)) {
                            int bstx = min(n-1, i-1);
                            int d1 = bstx - bjx, d2 = bstx - bkx;

                            ndp[j][k] = max(ndp[j][k], dp[d1][d2] + A[jx][jy] + A[kx][ky] + off);
                        }
                    }
                }
            }
        }

        dp = ndp;
    }

    cout << dp[0][0] << "\n";
	
    return 0;
}


