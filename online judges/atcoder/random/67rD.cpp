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

const int maxn = 5e3 + 5;
const int LOGN = 14;
const int maxm = 205;

int n, m;
ll dp[maxn];
ll a[maxn];
int b[maxn][maxm];
int st[maxn][LOGN][maxm];

void build(int id) {
    for(int i = 1; i <= n; i++) {
        st[i][0][id] = b[i][id];
    }

    for(int k = 1; (1 << k) <= n; k++) {
        int dis = 1 << (k-1);
        for(int i = 1; i + 2 * dis - 1 <= n; i++) {
            st[i][k][id] = max(st[i][k-1][id], st[i+dis][k-1][id]);
        }
    }
}

int query(int L, int R, int id) {
    int d = R-L+1;
    int k = 31 - __builtin_clz(d);
    int dis = 1 << k;

    return max(st[L][k][id], st[R-dis+1][k][id]);
}

ll C(int i, int j) {
    ll ans = 0;

    for(int k = 1; k <= m; k++)
        ans += query(i, j, k);

    ans -= a[j-1] - a[i-1];

    return ans;
}

void solve(int L, int R, int optL, int optR) {
    if(L > R) return;

    int mi = (L + R) >> 1;

    // calculate dp[mi]

    ll bestAns = LLONG_MIN; 
    int opt = -1;
    for(int i = optL; i <= min(optR, mi); i++) {
        ll currAns = C(i, mi);
        if(currAns > bestAns) {
            bestAns = currAns;
            opt = i;
        }
    }

    dp[mi] = bestAns;

    solve(L, mi-1, optL, opt);
    solve(mi+1, R, opt, optR);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;

    for(int i = 1; i <= n-1; i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) cin >> b[i][j];
    }
    
    for(int i = 1; i <= m; i++) build(i);

    solve(1, n, 1, n);

    cout << *max_element(dp+1, dp+1+n) << "\n";
    
    return 0;
}


