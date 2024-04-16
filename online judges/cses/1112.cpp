#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int m = s.size();

    if(n < m) {
        cout << 0 << "\n";
        return 0;
    }
    
    int T = 1;

    for(int i = 0; i < n-m; i++) {
        T = T * 26ll % mod;
    }

    vector<int> dp(n, 0);
    int ans = 0;

    for(int i = 0; i < n; i++) {
        if(i < m-1) continue;
        dp[i] = T;

        for(int j = 0; j < i-m+1; j++) {
            dp[i] = (dp[i] - dp[j]) % mod;
            if(dp[i] < 0) dp[i] += mod;
        }

        for(int j = i-m+1; j < i; j++) {
            int len = j-(i-m+1)+1;
            if(s.substr(0, len) == s.substr(m-len, len)) {
                dp[i] = (dp[i] - dp[j]) % mod;
                if(dp[i] < 0) dp[i] += mod;
            }
        }

        ans = (ans + dp[i]) % mod;
    }

    cout << ans << "\n";
	
    return 0;
}


