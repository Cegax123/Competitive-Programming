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
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        ll a[n+1];

        for(int i = 1; i <= n; i++) cin >> a[i];

        auto comp = [&] (int i, int j) {
            ll A = a[i];
            ll O = a[i];
            ll max_el = 0;

            for(int k = i; k <= j; k++) {
                A &= a[k];
                O |= a[k];
                max_el = max(max_el, a[k]);
            }

            return (A ^ O) >= max_el;
        };

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                cout << j << " " << i << ": ";
                cout << comp(j, i) << "\n";
            }
        }

        ll ans = (ll) n * (n+1) / 2;
        const int L = 60;

        int dp[n+1][L];
        memset(dp, 0, sizeof(dp));

        for(int i = 1; i <= n; i++) {
            int curr = 0;
            for(int j = 0; j < L; j++) {
                if((a[i] >> j)&1) {
                    dp[i][j] = dp[i-1][j] + 1;
                    curr = max(curr, dp[i][j]);
                }
            }
            cout << curr << " ";
            ans -= curr;
        }
        cout << endl;

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < 3; j++)
                cout << dp[i][j] << " ";
            cout << endl;
        }

        cout << ans << "\n";
    }

	
    return 0;
}


