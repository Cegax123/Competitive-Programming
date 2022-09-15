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

const int maxn = 2e5+5;
const ll INF = (ll) 1e18;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;

    vector<ll> dp(10, -INF);
    dp[0] = 0;

    for(int i = 0; i < n; i++) {
        int k; cin >> k;

        vector<vector<ll> > local(10, vector<ll> (4, -INF));

        for(int j = 0; j < 10; j++)
            local[j][0] = dp[j];
        
        for(int j = 0; j < k; j++) {
            int c, d; cin >> c >> d;

            vector<vector<ll> > next = local;

            for(int a = 0; a < 10; a++) {
                for(int b = 0; b <= 3; b++) {
                    if(b >= c) {
                        ll add = d;
                        if(a == 0) add *= 2;

                        next[a][b] = max(next[a][b], local[(a+9)%10][b-c] + add);
                    }
                }
            }

            local = next;
        }

        for(int a = 0; a < 10; a++) {
            for(int b = 0; b <= 3; b++) {
                dp[a] = max(dp[a], local[a][b]);
            }
        }
    }

    ll ans = 0;

    for(int i = 0; i < 10; i++)
        ans = max(ans, dp[i]);

    cout << ans << "\n";
	
    return 0;
}


