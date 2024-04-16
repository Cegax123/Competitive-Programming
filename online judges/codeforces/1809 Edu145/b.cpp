#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        ll l = 0, r = 1e9 + 10;

        while(l < r) {
            ll m = (l+r) >> 1;
            if((m+1) * (m+1) >= n) r = m;
            else l = m+1;
        }
        cout << l << "\n";
    }


    return 0;
}
