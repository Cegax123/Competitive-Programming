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
    int t; cin >> t;
    while(t--) {
        int p; cin >> p;
        vi a(p);
        for(int i = 0; i < p; i++) cin >> a[i];

        int q; cin >> q;
        vi b(q);
        for(int i = 0; i < q; i++) cin >> b[i];

        int r; cin >> r;
        vi c(r);
        for(int i = 0; i < r; i++) cin >> c[i];

        auto get = [](const vi& a, const vector<ll>& val, const vi& b) {
            vector<ll> p;

            for(int x : val) {
                if(p.empty()) p.pb(x);
                else p.pb(x + p.back());
            }

            vector<ll> nxt;

            for(int i = 0; i < (int) b.size(); i++) {
                int x = b[i];
                int l = 0, r = a.size()-1;
                while(l < r) {
                    int m = (l+r+1) >> 1;
                    if(a[m] <= x) l = m;
                    else r = m-1;
                }

                l = min(l, i);

                if(a[l] <= x) nxt.pb(p[l]);
                else nxt.pb(0);
            }

            return nxt;
        };

        vector<ll> init(p, 1);

        init = get(a, init, b);
        init = get(b, init, c);

        ll ans = accumulate(all(init), 0ll);

        cout << ans << "\n";
    }

	
    return 0;
}


