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

const int maxn = 4005;
const int maxk = 805;

int u[maxn][maxn];
int p[maxn][maxn];
int dp[maxn][maxk];

int C(int i, int j) {
    int sum = p[j][j] - 2 * (i == 0 ? 0 : p[i-1][j]) + (i == 0 ? 0 : p[i-1][i-1]);
    return sum / 2;
}

void solve(int L, int R, int optL, int optR, int id) {
    if(L > R) return;

    int mi = (L + R) >> 1;

    dp[mi][id] = INT_MAX;
    int opt = -1;

    for(int k = optL; k <= min(optR, mi); k++) {
        int currAns = (k == 0 ? 0 : dp[k-1][id-1]) + C(k, mi);

        if(currAns < dp[mi][id]) {
            dp[mi][id] = currAns;
            opt = k;
        }
    }

    solve(L, mi-1, optL, opt, id);
    solve(mi+1, R, opt, optR, id);
}

int main() {
    int n, k; scanf("%d %d", &n, &k);
    getchar();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char c = getchar();
            getchar();
            u[i][j] = c-'0';
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            p[i][j] = u[i][j];
            if(i) p[i][j] += p[i-1][j];
            if(j) p[i][j] += p[i][j-1];
            if(i and j) p[i][j] -= p[i-1][j-1];
        }
    }


    for(int i = 0; i < n; i++) {
        dp[i][0] = C(0, i);
    }

    for(int i = 1; i < k; i++) {
        solve(0, n-1, 0, n-1, i);
    }

    printf("%d\n", dp[n-1][k-1]);
	
    return 0;
}


