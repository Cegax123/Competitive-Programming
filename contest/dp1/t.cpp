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

const ll mod = 1e9+7;

ll sum(ll a, ll b) {return (a+b)%mod;}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	int dp[n+5];

    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;

    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i-1];
        dp[i] = sum(dp[i], dp[i-2]);
        dp[i] = sum(dp[i], dp[i-3]);
    }

    cout << dp[n] << "\n";
	
	return 0;
}

