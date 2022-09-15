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

ll a, b, c, d;
ll L1, L2;

ll h(ll x) {
    if(x <= L1) 
        return x * d * b;
    return  L1 * d * b + (c + d - d * L2) * b;
}

ll sum(ll x) {
    if(x <= L1) 
        return x * (x + 1ll) / 2ll * d * b;
    return h(L2) + sum(L1);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> a >> b >> c >> d;
        L1 = c/d, L2 = (c+d-1)/d;


        if(a > h(L2)) {
            cout << -1 << "\n";
            continue;
        }

        ll l = 0, r = L2;

        while(l < r) {
            ll m = (l + r) >> 1;
            if(h(m)-a >= 0) r = m;
            else l = m+1;
        }

        cout << l * a - sum(l-1) << "\n";
    }

	
    return 0;
}


