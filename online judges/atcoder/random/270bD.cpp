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
    int n, k; cin >> n >> k;
    int a[k];

    for(int i = 0; i < k; i++) cin >> a[i];

    int dp[n+1];
    memset(dp, -1, sizeof(dp));

    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < k; j++) {
            if(a[j] <= i) {
                dp[i] = max(dp[i], i-dp[i-a[j]]);
            }
        }
    }

    cout << dp[n] << "\n";
	
    return 0;
}


