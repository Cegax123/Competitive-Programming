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

const int maxn = 1e6;
const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    vi dp(maxn+1, INF);
    dp[1] = 0;

    for(int i = 1; i <= maxn; i++) {
        if(i*2 <= maxn) dp[i*2] = min(dp[i*2], dp[i]+1);
        if(i*3 <= maxn) dp[i*3] = min(dp[i*3], dp[i]+1);
        if(i+1 <= maxn) dp[i+1] = min(dp[i+1], dp[i]+1);
    }

    int n; cin >> n;

    cout << dp[n] << "\n";
	
	return 0;
}

