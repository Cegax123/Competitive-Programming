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
    int n, r; cin >> n >> r;
    vii good, bad;

    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        if(b >= 0) good.push_back(make_pair(a, b));
        else bad.push_back(make_pair(a, b));
    }

    sort(all(good));

    auto cmp = [] (ii& a, ii &b) {
        return a.first+a.second > b.first+b.second;
    };

    sort(all(bad), cmp);

    vii tasks;

    tasks.pb(make_pair(-1, -1));

    // Indexing from 1
    for(auto x : good) tasks.pb(x);
    for(auto x : bad) tasks.pb(x);

    int dp[n+1][n+1];
    memset(dp, -1, sizeof(dp));

    for(int i = 0; i <= n; i++) {
        dp[i][0] = r;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            for(int k = j-1; k < i; k++) {
                if(dp[k][j-1] >= tasks[i].first) {
                    dp[i][j] = max(dp[i][j], dp[k][j-1] + tasks[i].second);
                }
            }
        }
    }

    int ans = 0;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            if(dp[i][j] >= 0) {
                ans = max(ans, j);
            }
        }
    }

    cout << ans << "\n";
	
    return 0;
}


