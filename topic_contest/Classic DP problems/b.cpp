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
    int tt; cin >> tt;
    for(int tc = 1; tc <= tt; tc++) {
        int n; cin >> n;
        n--;
        int a[n];

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int dp[n], p[n];
        dp[0] = a[0];
        p[0] = 0;

        for(int i = 1; i < n; i++) {
            p[i] = i;
            dp[i] = a[i];

            if(dp[i-1] + a[i] >= dp[i]) {
                p[i] = p[i-1];
                dp[i] = dp[i-1] + a[i];
            }
        }

        int ans = -1;
        int l = n, r = n;

        for(int i = 0; i < n; i++) {
            if(dp[i] > ans) {
                r = i;
                l = p[i];
                ans = dp[i];
            }
            else if(dp[i] == ans) {
                // [l, r], [p[i], i]

                if(i-p[i] == r-l) {
                    if(i < r) {
                        r = i;
                        l = p[i];
                    }
                }
                else if(i-p[i] > r-l) {
                    r = i;
                    l = p[i];
                }
            }
        }

        if(ans == -1) cout << "Route " << tc << " has no nice parts\n";
        else {
            cout << "The nicest part of route " << tc << " is between stops " << l+1 << " and " << r+2 << "\n";
        }
    }

	
    return 0;
}


