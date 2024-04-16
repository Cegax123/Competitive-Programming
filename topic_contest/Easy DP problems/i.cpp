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
    const int maxn = 1e6+5;

    int dp[maxn];
    dp[1] = 0;

	for(int i = 2; i < maxn; i++) {
        dp[i] = dp[i-1] + 1;

        if(i % 2 == 0) dp[i] = min(dp[i], dp[i/2] + 1);
        if(i % 3 == 0) dp[i] = min(dp[i], dp[i/3] + 1);
    }

    int n; cin >> n;
    cout << dp[n] << "\n";

    return 0;
}


