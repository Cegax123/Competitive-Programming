#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int k; cin >> k;
        int a[n], x[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> x[i];

        vector<int> h(n+1, 0);

        for(int i = 0; i < n; i++) h[abs(x[i])] += a[i];

        long long lft = 0;
        bool cmp = 1;
        for(int i = 1; i <= n; i++) {
            lft += k;

            if(h[i] > lft) {
                cmp = 0;
                break;
            }

            lft -= h[i];
        }

        cout << (cmp ? "YES\n" : "NO\n");
    }


    return 0;
}
