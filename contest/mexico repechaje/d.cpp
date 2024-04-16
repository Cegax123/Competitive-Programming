#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
typedef long long ll;
typedef pair<long long, long long> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//cout << setprecision(12) << fixed;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;

typedef tree<
ii,
null_type,
less<ii>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ordered_set s;

    int m; cin >> m;
    vector<ll> a;
    vector<int> pos(m+1);

    for(int i = 1; i <= m; i++) {
        int op; cin >> op;
        if(op == 1) {
            pos[i] = a.size();
            ll x; cin >> x;
            a.pb(x);
            s.insert({a[pos[i]], pos[i]});
        }
        else if(op == 2) {
            int c; cin >> c;
            c = pos[c];
            s.erase({a[c], c});
        }
        else if(op == 3) {
            int c; cin >> c;
            c = pos[c];
            s.erase({a[c], c});

            ll x; cin >> x;
            a[c] += x;

            s.insert({a[c], c});
        }
        else {
            int c; cin >> c;
            c = pos[c];

            //cout << a[c] << endl;

            int k = s.order_of_key({a[c], -1});

            cout << s.order_of_key({a[c], -1}) << "\n";

            assert(a[c] == (*(s.find_by_order(k))).first);
        }
    }

    return 0;
}


