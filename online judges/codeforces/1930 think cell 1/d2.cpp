#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int ind = i;

                int cnt = 0;

                while(ind <= j) {
                    if(s[ind] == '0') {
                        ind++;
                        continue;
                    }
                    int r = ind;
                    while(r <= j and s[r] == '1') {
                        r++;
                    }
                    
                    int len = r-ind;
                    cnt += (len+2)/3;
                    ind = r;
                }
            
                ans += cnt;
            }
        }
        cout << ans << "\n";
    }


    return 0;
}

