#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll x) {
    ll d = 0;
    ll lmt = 0;
    int i = 0;
    ll ans = 0;
    while(lmt < x) {
        ans += d * i;
        lmt = lmt * 10 + 9;
        if(d == 0) d = 9;
        else d *= 10;
        i++;
    }
    lmt /= 10;
    ans += (x-lmt) * (i);
    return ans;
}

int main() {
    int q; cin >> q;
    while(q--) {
        ll k; cin >> k;
        ll l = 1, r = (ll) 1e17;
        
        while(l < r) {
            ll m = (l+r+1) >> 1;
            if(f(m) < k) l = m;
            else r = m-1;
        }

        k -= f(l);

        l++;

        vector<int> dgts;

        while(l) {
            dgts.push_back(l % 10);
            l /= 10;
        }

        reverse(dgts.begin(), dgts.end());
        cout << dgts[k-1] << "\n";
    }

    return 0;
}
