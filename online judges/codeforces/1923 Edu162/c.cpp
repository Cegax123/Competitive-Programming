#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, q; cin >> n >> q;
        int c[n];
        int cnt[n];
        for(int i = 0; i < n; i++) {
            cin >> c[i];
            cnt[i] = c[i] == 1;
        }
        ll s[n];
        s[0] = c[0]-1;
        for(int i = 1; i < n; i++) {
            s[i] = s[i-1] + c[i] - 1;
            cnt[i] += cnt[i-1];
        }

        while(q--) {
            int l, r; cin >> l >> r;
            l--; r--;
            if(l == r) {
                cout << "NO\n";
                continue;
            }

            ll sum = s[r] - (l == 0 ? 0 : s[l-1]);
            int num = cnt[r] - (l == 0 ? 0 : cnt[l-1]);

            if(sum >= num) cout << "YES\n";
            else cout << "NO\n";
        }

    }


    return 0;
}
