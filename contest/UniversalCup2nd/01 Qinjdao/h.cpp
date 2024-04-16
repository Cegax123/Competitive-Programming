#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int n = s.size();
        long long ans = 0;

        for(int i = 1; i <= n; i++) {
            ans += i * 1ll * (n+1-i);
        }

        ans *= 2;

        for(int i = 0; i < n; i++) {
            if(i == 0) {
                if(s[i] == '1') ans -= n;
            }
            else {
                if(s[i] == '0' and s[i-1] == '1') {
                    ans -= i * 1ll * (n-i);
                }
                else if(s[i] == '1' and s[i-1] == '1') {
                    ans -= n-i;
                }
                else if(s[i] == '1' and s[i-1] == '0') {
                    ans -= (i+1) * 1ll * (n-i);
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
