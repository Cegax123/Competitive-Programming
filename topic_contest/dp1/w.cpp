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

const int mod = 1e9+7;
const int E = 26;

ll sum(ll a, ll b) {
    ll ans = (a+b)%mod;
    return (ans+mod)%mod;
}

ll mul(ll a, ll b) {return a*b%mod;}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int n = s.size();

        int last[E];
        memset(last, -1, sizeof(last));

        int dp[n+1];
        memset(dp, 0, sizeof(dp));

        dp[0] = 1;

        for(int i = 1; i <= n; i++) {
            int k = last[s[i-1]-'A'];
            dp[i] = sum(mul(2, dp[i-1]), -(k == -1 ? 0 : dp[k-1]));

            last[s[i-1]-'A'] = i;
        }

        cout << dp[n] << "\n";
    }
	
	return 0;
}

