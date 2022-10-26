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

const int maxn = 4000;
const ll mod = 1e9+7;

ll sum(ll a, ll b) {return (a+b)%mod;}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s, t; cin >> s >> t;

    int n = s.size(), k = t.size();

    vi dp(k+1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; i++) {
        vi ndp = dp;
        for(int j = 1; j <= k; j++) {
            if(t[j-1] == s[i-1]) 
                ndp[j] = sum(ndp[j], dp[j-1]);
        }
        dp = ndp;
    }
    
    cout << dp[k] << "\n";
	
	return 0;
}

