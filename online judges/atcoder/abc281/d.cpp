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
    int n, k, d; cin >> n >> k >> d;

    ll dp[n+1][d+1];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        
        for(int j = n-1; j >= 0; j--) {
            for(int bd = 0; bd < d; bd++) {
                if(dp[j][bd] == -1) continue;
                dp[j+1][(bd + a % d)%d] = max(dp[j+1][(bd + a % d)%d], dp[j][bd] + a);
            }
        }
    }

    cout << dp[k][0] << "\n";
	
    return 0;
}


