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

const int E = 26;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int n = s.size();

        vi prev(n);
        vi last(E, -1);

        for(int i = 0; i < n; i++) {
            prev[i] = last[s[i]-'a'];
            last[s[i]-'a'] = i;
        }

        int dp[n];
        dp[0] = 1;

        for(int i = 1; i < n; i++) {
            dp[i] = dp[i-1]+1;

            if(prev[i] != -1) {
                if(prev[i] == 0) dp[i] = min(dp[i], i+1-2);
                else dp[i] = min(dp[i], dp[prev[i]-1]+i-prev[i]-1);
            }
        }

        cout << dp[n-1] << "\n";
    }
	
	
	return 0;
}

