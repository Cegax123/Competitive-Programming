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

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;

typedef tree<
pair<ll, ll>,
null_type,
less<pair<ll, ll>>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int t; cin >> t;
    int t; t = 1;
    while(t--) {
        ll n, k, m, c, d; cin >> n >> k >> m >> c >> d;

        ll a[n];

        for(int i = 0; i < n; i++) cin >> a[i];

        ll b[n];
        ll add = c;
        for(int i = 0; i < n; i++) {
            b[i] = a[i] + add;
            add += d;
        }

        ordered_set ob, oa;

        for(int i = 0; i < m-1; i++) {
            ob.insert({-b[i], i});
        }

        for(int i = m-1; i < n; i++) {
            oa.insert({-a[i], i});
        }

        const ll INF = (ll) 1e16;
        ll ans = 0;

        for(int i = m-1; i < n; i++) {
            ob.insert({-b[i], i});
            oa.erase({-a[i], i});
            if(i-m >= 0) {
                oa.insert({-a[i-m], i-m});
                ob.erase({-b[i-m], i-m});

            }

            assert((int) oa.size() + (int) ob.size() == n);

            ll add = (ll) d * (i-m+1);

            ll l = 0, r = (ll) INF;

            while(l < r) {
                ll mi = (l+r) >> 1;
                
                int cnt = ob.order_of_key({-mi, -INF}) + oa.order_of_key({-mi+add, -INF});

                if(cnt < k) r = mi;
                else l = mi+1;
            }

            //cout << i << " " << l << " " << add;

            ans = max(ans, l-add);
        }

        sort(a, a + n);

        ans = max(ans, a[n-k]);

        cout << ans << "\n";
    }
	
    return 0;
}


