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
        int n; cin >> n;
        int m; cin >> m;

        vi a(n+1, 0);

        ii seg[m];
        for(int i = 0; i < m; i++) cin >> seg[i].first >> seg[i].second;

        int q; cin >> q;
        int b[q+1];

        for(int i = 1; i <= q; i++) cin >> b[i];

        auto cmp = [&](int x) {
            for(int i = 1; i <= x; i++) a[b[i]] = 1;

            int pr[n+1];
            pr[0] = a[0];
            for(int i = 1; i <= n; i++) pr[i] = pr[i-1] + a[i];

            bool ans = false;
            for(int i = 0; i < m; i++) {
                int sum = pr[seg[i].second] - pr[seg[i].first-1];
                if(sum > seg[i].second - seg[i].first + 1 - sum) ans = true;
            }

            for(int i = 1; i <= x; i++) a[b[i]] = 0;
            return ans;
        };

        int l = 0, r = q;
        while(l < r) {
            int m = (l+r) >> 1;
            if(cmp(m)) r = m;
            else l = m+1;
        }

        if(cmp(l)) cout << l << "\n";
        else cout << -1 << "\n";
    }

	
    return 0;
}


