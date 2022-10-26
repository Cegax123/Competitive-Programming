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
    for(int tc = 1; tc <= t; tc++) {
        int n, m, p; cin >> n >> m >> p;

        int a[n+1][m+1];

        for(int i = 1; i <= n; i++) 
            for(int j = 1; j <= m; j++)
                cin >> a[i][j];

        ll dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+a[i][j];
            }
        }

        int area = 0;
        ll sum = 0;
        
        for(int i = 1; i <= n; i++) {
            vector<ll> b(m+1, 0);
            for(int j = i; j <= n; j++) {
                for(int k = 1; k <= m; k++)
                    b[k] += a[j][k];
                
                int l = 1, r = 0;
                ll curr = 0;

                for(int k = 1; k <= m; k++) {
                    if(r < l) {
                        r = k;
                        curr = b[k];
                    }
                    while(r+1 <= m and curr + b[r+1] <= p) {
                        curr += b[r+1];
                        r++;
                    }

                    if(curr <= p) {
                        int curr_area = (j-i+1) * (r-l+1);
                        if(area < curr_area) {
                            area = curr_area;
                            sum = curr;
                        }
                        else if(area == curr_area)
                            sum = min(sum, curr);
                    }

                    curr -= b[l];
                    l++;
                }
            }
        }

        cout << "Case #" << tc << ": ";
        cout << area << " " << sum << "\n";
    }
	
	return 0;
}

