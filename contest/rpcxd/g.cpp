#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//cout << setprecision(12) << fixed;



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n; cin >> n;
    int k; cin >> k;

    ll p[k];
    for(int i = 0; i < k; i++) cin >> p[i];

    auto get_kth = [&](ll x) {
        ll ans = x;
        for(int i = 1; i < (1 << k); i++) {
            ll prod = 1;
            int cnt = 0;

            for(int j = 0; j < k; j++) {
                if((i >> j)&1) {
                    prod *= p[j];
                    cnt++;
                }
            }

            if(cnt&1) ans -= x/prod;
            else ans += x/prod;

            //cout << cnt << " " << x/prod << "\n";
        }

        return ans;
    };

    //cout << get_kth(1) << endl;

    ll l = 1, r = (ll) 1e18;

    while(l < r) {
        ll m = (l+r) >> 1;

        if(get_kth(m) >= n) r = m;
        else l = m + 1;
    }
    
    cout << l << "\n";

    return 0;
}


