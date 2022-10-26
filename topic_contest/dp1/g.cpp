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

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, k; cin >> n >> k;
	
    auto sum = [&](ll a, ll b) {return (a+b)%mod;};

    int dp[n+1];
    memset(dp, 0, sizeof(dp));

    dp[1] = 1;

    for(int i = 0; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(i+j <= n) dp[i+j] = sum(dp[i+j], dp[i]);
        }
    }

    cout << dp[n] << "\n";
	
	return 0;
}

