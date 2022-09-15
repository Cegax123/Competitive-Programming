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

const int maxr = 6e4+5;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, r; cin >> n >> r;

    vii u, d;

    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;

        if(b >= 0) u.pb({a, b});
        else d.pb({a, -b});
    }

    sort(all(u), [&] (const ii& x, const ii& y) {
            return x.first < y.first;
            });

    sort(all(d), [&] (const ii& x, const ii& y) {
            return x.first - x.second > y.first - y.second;
            });

    int dp[maxr];
    memset(dp, -1, sizeof(dp));

    dp[r] = 0;

    for(auto t : u) { 
        for(int i = maxr-1; i >= 0; i--) { 
            if(dp[i] == -1) continue; 
            if(i >= t.first and i + t.second < maxr) dp[i + t.second] = max(dp[i + t.second], dp[i] + 1);
        }
    }

    for(auto t : d) {
        for(int i = 0; i < maxr; i++) {
            if(dp[i] == -1) continue;
            if(i >= t.first and i-t.second >= 0) {
                dp[i-t.second] = max(dp[i-t.second], dp[i] + 1);
            }
        }
    }
	
    int ans = 0;

    for(int i = 0; i < maxr; i++)
        ans = max(ans, dp[i]);

    cout << ans << "\n";

    return 0;
}


