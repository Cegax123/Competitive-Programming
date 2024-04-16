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
    int a, n, m; cin >> a >> n >> m;
    vector<bool> rain(a+1, 0);
    
    for(int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        for(int j = l+1; j <= r; j++)
            rain[j] = 1;
    }

    vii um;

    for(int i = 0; i < m; i++) {
        int x, p; cin >> x >> p;
        um.pb({x, p});
    }

    sort(all(um));

    int cnt = 1;
    vi dp(m+1, 0);

    for(int i = 0; i <= a; i++) {
        vi ndp(m+1, 0);

        int mn = INF;
        for(int j = 1; j < cnt; j++) {
            ndp[j] = dp[j] + um[j-1].second;
            mn = min(mn, ndp[j]);
        }

        ndp[0] = mn;

        if(!rain[i]) {
            for(int j = 0; j < cnt; j++)
                ndp[0] = min(ndp[0], dp[j]);
        }

        while(cnt <= m and i == um[cnt-1].first) {
            ndp[cnt] = ndp[0];
            cnt++;
        }
        
        dp = ndp;
    }

    if(dp[0] == INF) cout << -1 << "\n";
    else cout << dp[0] << "\n";
	
    return 0;
}


