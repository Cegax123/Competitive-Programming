// LINK: https://atcoder.jp/contests/cf17-final/tasks/cf17_final_d

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

const ll INF = (ll) 1e18;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    vii a(n);

    for(int i = 0; i < n; i++) 
        cin >> a[i].second >> a[i].first;

    sort(all(a), [&] (const ii& a, const ii& b) {
            return a.first + a.second < b.first + b.second;
    });

    // for(int i = 0; i < n; i++) {
    //     cout << a[i].first << " " << a[i].second << endl;
    // }

    vector<ll> dp(n, INF);
    dp[0] = a[0].first;

    int ans = 1;

    for(int i = 1; i < n; i++) {
        for(int j = n-1; j > 0; j--) {
            if(dp[j-1] != INF and dp[j-1] <= a[i].second) {
                dp[j] = min(dp[j], dp[j-1] + a[i].first);
                ans = max(ans, j+1);
            }
        }

        dp[0] = min(dp[0], (ll) a[i].first);
    }

    cout << ans << "\n";
		
	return 0;
}

