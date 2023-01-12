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
    vector<vi> a(n+1);

    bool cmp = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            int x; cin >> x;
            if(i == j) {
                if(x == 2) cmp = 0;
            }
            else a[j].pb(x);
        }
    }

    if(cmp == 0) {
        cout << 0 << "\n";
        return 0;
    }

    int L[n+1], R[n+1];

    for(int i = 1; i <= n; i++) {
        int last2 = -1, first1 = a[i].size();

        for(int j = 0; j < (int) a[i].size(); j++) 
            if(a[i][j] == 2) last2 = j;
        for(int j = (int) a[i].size()-1; j >= 0; j--)
            if(a[i][j] == 1) first1 = j;

        if(last2 > first1) cmp = 0;
        else {
            L[i] = a[i].size()-first1;
            R[i] = a[i].size()-last2-1;
        }
    }

    if(cmp == 0) {
        cout << 0 << "\n";
        return 0;
    }

    const int maxn = 100;

    ll dp[maxn + 5][maxn + 5][2];
    memset(dp, 0, sizeof(dp));

    const ll mod = 998244353;

    dp[1][0][0] = dp[1][0][1] = 1;

    auto sum = [](ll& a, ll& b) {
        a = (a+b) % mod;
    };

    for(int i = 1; i < n; i++) {
        for(int j = L[i]; j <= R[i]; j++) {
            for(int t = 0; t <= 1; t++) {
                if(L[i+1] == 0) sum(dp[i+1][0][1-t], dp[i][j][t]);
                if(L[i+1] <= j+1 and j+1 <= R[i+1]) sum(dp[i+1][j+1][t], dp[i][j][t]);
            }
        }
    }

    ll ans = 0;

    for(int j = L[n]; j <= R[n]; j++) {
        ll add = (dp[n][j][0] + dp[n][j][1]) % mod;
        sum(ans, add);
    }

    cout << ans << "\n";
	
    return 0;
}


