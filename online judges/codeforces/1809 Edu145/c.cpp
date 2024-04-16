#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        int tmpk = k;
        vector<int> a(1, 0);

        if(k < n) {
            for(int i = 0; i < k; i++) a.pb(k-i);
            for(int i = 0; i < n-k; i++) a.pb(-i-1);
        }
        else {
            k -= n;
            int lmt = n-1;
            int x = 1;

            while(lmt and k >= lmt) {
                a.pb(x);
                k -= lmt;
                lmt--;
                x++;
            }

            if(x <= n) {
                a.pb(n-k);
                for(int i = n; i >= x; i--) if(i != n-k) a.pb(i);
            }
        }

        assert((int) a.size() == n+1);

        int cnt = 0;
        for(int i = 0; i <= n; i++) {
            for(int j = i+1; j <= n; j++)
                cnt += (a[j] > a[i]);
        }

        assert(tmpk == cnt);

        for(int i = 1; i <= n; i++)
            cout << a[i]-a[i-1] << " ";
        cout << "\n";
    }


    return 0;
}
