#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n, m; cin >> n >> m;
    ll k; cin >> k;

    int g = __gcd(n, m);
    ll d = n * 1ll * m / g;

    ll l = 0, r = (ll) 1e18;

    while(l < r) {
        ll tm = (l+r) >> 1;
        ll cnt = 0;
        cnt += tm / n;
        cnt += tm / m;
        cnt -= tm / d;
        cnt -= tm / d;

        if(cnt >= k) r = tm;
        else l = tm+1;
    }

    cout << l << "\n";

    return 0;
}
