#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];
        ll s[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(i == 0) s[0] = a[0];
            else s[i] = s[i-1] + a[i];
        }

        int lenL[n], lenR[n];
        lenL[0] = 0;

        for(int i = 1; i < n; i++) {
            if(a[i] == a[i-1]) lenL[i] = lenL[i-1];
            else lenL[i] = i;
        }

        lenR[n-1] = n-1;

        for(int i = n-2; i >= 0; i--) {
            if(a[i] == a[i+1]) lenR[i] = lenR[i+1];
            else lenR[i] = i;
        }

        for(int i = 0; i < n; i++) {
            int ans = -1;
            if(i+1 < n) {
                int l = i+1, r = n-1;

                while(l < r) {
                    int m = (l+r) >> 1;

                    ll sum = 0;

                    if(lenR[i+1] >= m) sum = a[i+1];
                    else sum = s[m] - s[i];

                    if(sum > a[i]) r = m;
                    else l = m+1;

                }

                ll sum = 0;
                if(lenR[i+1] >= l) sum = a[i+1];
                else sum = s[l] - s[i];

                if(sum > a[i]) ans = l-i;
                
            }

            if(i) {
                int l = 0, r = i-1;
                while(l < r) {
                    int m = (l+r+1) >> 1;

                    ll sum = 0;

                    if(lenL[i-1] <= m) sum = a[i-1];
                    else sum = s[i-1] - (m == 0 ? 0 : s[m-1]);

                    if(sum > a[i]) l = m;
                    else r = m-1;;
                }

                ll sum = 0;
                if(lenL[i-1] <= l) sum = a[i-1];
                else sum = s[i-1] - (l == 0 ? 0 : s[l-1]);

                if(sum > a[i]) {
                    if(ans == -1) ans = i-l;
                    ans = min(ans, i-l);
                }
            }

            cout << ans << " ";
        }
        cout << "\n";
    }


    return 0;
}
