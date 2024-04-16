#include<bits/stdc++.h>
using namespace std;



int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[2*n];
        for(int i = 0; i < 2*n; i++) cin >> a[i];
        sort(a, a+2*n);

        int ans = 0;
        for(int i = 0; i < 2*n; i += 2) ans += a[i];

        cout << ans << "\n";
    }


    return 0;
}
