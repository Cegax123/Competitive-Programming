#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int len = j-i+1;
                set<int> s;
                for(int mask = 0; mask < (1 << len); mask++) {
                    int x = 0;
                    for(int k = 0; k < len; k++) {
                        if((mask>>k)&1) x ^= a[i+k];
                    }
                    s.insert(x);
                }
                
                ans += s.size();
            }
        }

        cout << ans << "\n";
    }
    

    return 0;
}
