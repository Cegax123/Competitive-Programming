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
        int a[n], b[n];
        int l = n, r = -1;

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        for(int i = 0; i < n; i++) {
            if(a[i] != b[i]) {
                l = i;
                break;
            }
        }

        for(int i = n-1; i >= 0; i--) {
            if(a[i] != b[i]) {
                r = i;
                break;
            }
        }

        if(l > r) {
            int dp[n];
            dp[0] = 1;

            int ans = 1;

            for(int i = 1; i < n; i++) {
                if(a[i] >= a[i-1]) {
                    dp[i] = dp[i-1] + 1;
                }
                else dp[i] = 1;

                ans = max(ans, dp[i]);
            }

            cout << ans << "\n";
            continue;
        }

        while(l-1 >= 0) {
            if(b[l-1] <= b[l]) {
                l--;
            }
            else break;
        }

        while(r+1 < n) {
            if(b[r+1] >= b[r]) {
                r++;
            }
            else break;
        }

        cout << l+1 << " " << r+1 << "\n";
    }

	
    return 0;
}


