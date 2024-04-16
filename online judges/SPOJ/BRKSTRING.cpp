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

const int maxm = 1005;
ll dp[maxm][maxm];
int opt[maxm][maxm];
ll a[maxm];

ll sum(int i, int j) {
    if(i == 0) return a[j-1];
    return a[j-1] - a[i-1];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; 

    while(cin >> n >> m) {
        for(int i = 0; i < m; i++)
            cin >> a[i];

        m++;
        a[m-1] = n;

        for(int len = 2; len <= m+1; len++) {
            for(int i = 0; i + len - 1 <= m; i++) {
                int j = i + len - 1;

                if(len == 2) {
                    dp[i][j] = 0;
                    opt[i][j] = i;
                    continue;
                }

                int minK = opt[i][j-1], maxK = opt[i+1][j];
                dp[i][j] = (ll) 1e18;

                for(int k = minK; k <= maxK; k++) {
                    if(dp[i][j] > dp[i][k] + dp[k][j]) {
                        dp[i][j] = dp[i][k] + dp[k][j];
                        opt[i][j] = k;
                    }
                }

                dp[i][j] += sum(i, j);
            }
        }

        cout << dp[0][m] << "\n";
    }

	
    return 0;
}


