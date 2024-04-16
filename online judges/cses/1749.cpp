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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ordered_set s;

    int n; cin >> n;
    int x[n];
    for(int i = 0; i < n; i++) cin >> x[i];

    for(int i = 0; i < n; i++) s.insert(i);

    for(int i = 0; i < n; i++) {
        int p; cin >> p; p--;
        int pos = *s.find_by_order(p);
        cout << x[pos] << " ";
        s.erase(pos);
    }
	
    return 0;
}


