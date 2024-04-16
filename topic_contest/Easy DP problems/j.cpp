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
    int n; cin >> n;
    int h[n];
    for(int i = 0; i < n; i++) cin >> h[i];

    ll dp[n];
    dp[0] = 0;

    for(int i = 1; i < n; i++) {
        dp[i] = (ll) 1e18;

        for(int j = 0; j < i; j++) {
            dp[i] = min(dp[i], dp[j] + abs(h[i]-h[j]));
        }
    }

    cout << dp[n-1] << "\n";
	
    return 0;
}


