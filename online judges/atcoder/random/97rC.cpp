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

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n; cin >> n;
    int cnta[2 * n + 1][n+2], cntb[2 * n + 1][n+2];
    int posa[n + 1], posb[n + 1];

    memset(cnta, 0, sizeof(cnta));
    memset(cntb, 0, sizeof(cntb)); 

    for(int i = 1; i <= 2 * n; i++) {
        char c; cin >> c;
        int v; cin >> v;

        if(c == 'W') {
            cnta[i][v]++;
            posa[v] = i;
        }
        else {
            cntb[i][v]++;
            posb[v] = i;
        }
    }

    for(int i = 1; i <= 2 * n; i++) {
        for(int j = n; j >= 1; j--) {
            cnta[i][j] += cnta[i][j+1];
            cntb[i][j] += cntb[i][j+1];
        }
    }

    for(int j = 1; j <= n+1; j++) {
        for(int i = 1; i <= 2 * n; i++) {
            cnta[i][j] += cnta[i-1][j];
            cntb[i][j] += cntb[i-1][j];
        }
    }

    // for(int i = 1; i <= 2 * n; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         cout << i << " " << j << " " << cnta[i][j] << "\n";
    //     }
    // }

    vector<vi> dp(n+1, vi(n+1, INF));
    dp[0][0] = 0;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0 and j == 0) continue;

            if(i) dp[i][j] = min(dp[i][j], dp[i-1][j] + (i + j) - posa[i] + cnta[posa[i]-1][i+1] + cntb[posa[i]-1][j+1]);
            if(j) dp[i][j] = min(dp[i][j], dp[i][j-1] + (i + j) - posb[j] + cnta[posb[j]-1][i+1] + cntb[posb[j]-1][j+1]);

            // cout << i << " " << j << " " << dp[i][j] << "\n";
        }
    }


    cout << dp[n][n] << "\n";

    return 0;
}


