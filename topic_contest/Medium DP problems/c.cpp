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
    int mx = 0, cnt = 1;
    string s; cin >> s;
    int n = s.size();

    int dp[n];
    memset(dp, -1, sizeof(dp));

    //cout << dp[0] << " ";

    for(int i = 1; i < n; i++) {
        if(s[i] == '(') {
            //cout << dp[i] << " ";
            continue;
        }
        dp[i] = -1;
        if(dp[i-1] == -1) {
            if(s[i-1] == '(') {
                dp[i] = i-1;
            }
        }
        else {
            int l = dp[i-1] - 1;
            if(l >= 0 and s[l] == '(') {
                dp[i] = l;
            }
        }

        if(dp[i] >= 1 and dp[dp[i]-1] != -1) dp[i] = dp[dp[i]-1];

        if(dp[i] != -1) {
            int len = i-dp[i] + 1;
            if(len > mx) {
                mx = len;
                cnt = 1;
            }
            else if(len == mx) cnt++;
        }
        //cout << dp[i] << " ";
    }

    cout << mx << " " << cnt << "\n";
	
    return 0;
}


