#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, c; cin >> n >> c;

        ll ans = (c+2) * 1ll * (c+1) / 2;

        int s[n];
        for(int i = 0; i < n; i++) cin >> s[i];

        ll d1 = 0;
        int lasteven= -1, lastodd = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] % 2 == 0) {
                int k = s[i]/2;
                d1 += min(k+1, c-k+1);
                d1 += max(0, (c - s[i]/2) - (s[i]/2) + 1);
            }
            else {
                d1 += min((s[i]+1)/ 2, (2*c-s[i]+1)/2);
                d1 += max(0, ((2*c-s[i]) - (s[i]))/2 + 1);
            }
        }


        ll d2 = 0;
        int even = 0, odd = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] % 2 == 0) {
                even++;
                d2 += even;
            }
            else {
                odd++;
                d2 += odd;
            }
        }
        
        cout << ans-(d1-d2) << "\n";
    }


    return 0;
}
