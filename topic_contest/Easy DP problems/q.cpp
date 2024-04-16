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
    const int mod = 1e9 + 7;

    string s, t; cin >> s >> t;

    int n = s.size(), m = t.size();

    vi dp(m, 0);

    for(char c : s) {
        vi ndp = dp;
        for(int i = 0; i < (int) t.size(); i++) {
            if(t[i] == c) {
                if(i == 0) ndp[0]++;
                else ndp[i] = (ndp[i] + dp[i-1]) % mod;
            }
        }

        dp = ndp;
    }

    cout << dp[m-1] << "\n";
	
    return 0;
}


