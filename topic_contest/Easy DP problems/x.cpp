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
    const int maxn = 3005;
    const int mod = 1e9 + 7;

    int n; cin >> n;
    string s; cin >> s;

    vi sum(n+1, 0);
    sum[1] = 1;

    for(int i = 2; i <= n; i++) {
        vi dp(n+1, 0);
        for(int j = 1; j <= i; j++) {
            if(s[i-2] == '<') {
                dp[j] = sum[j-1];
            }
            else {
                dp[j] = (sum[i-1] - sum[j-1]) % mod;
                if(dp[j] < 0) dp[j] += mod;
            }
        }

        sum[0] = 0;
        for(int j = 1; j <= i; j++)
            sum[j] = (dp[j] + sum[j-1]) % mod;
    }

    cout << sum[n] << "\n";
	
    return 0;
}


