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
    int a, b; cin >> a >> b;
    int n; cin >> n;

    while(n--) {
        int l, t, m; cin >> l >> t >> m;

        auto f = [&](int x) {
            return x * 1ll * (x-1) / 2;
        };

        auto cmp = [&](int r) {
            if(b * 1ll * (r-1) + a > t) return false;
            ll fact = f(r) - f(l-1);
            if(fact > (ll) 2e18 / b) return false;
            ll sum = a * 1ll * (r-l+1) + b * 1ll * fact;
            return sum <= (m * 1ll * t);
        };

        ll L = l, R = l + max(t, m) + 100;

        while(L < R) {
            ll m = (L+R+1) >> 1;
            if(cmp(m)) L = m;
            else R = m-1;
        }

        cout << (cmp(L) ? L : -1) << "\n";
    }
	
    return 0;
}


