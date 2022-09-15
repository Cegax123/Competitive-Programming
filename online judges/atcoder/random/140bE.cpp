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
    int n; cin >> n;
    int pos[n+1];

    for(int i = 1; i <= n; i++) {
    	int x; cin >> x;
    	pos[x] = i;
    }

    ll ans = 0;

    set<int> s;

    s.insert(-1);
    s.insert(0);
    s.insert(n+1);
    s.insert(n+2);
	
    for(int i = n; i >= 1; i--) {
    	auto it = s.upper_bound(pos[i]);

    	ll R1 = *it; it++;
    	ll R2 = *it; it--;it--;
    	ll L1 = *it; it--;
    	ll L2 = *it;

    	R2 = min(R2, (ll) n+1);
    	L2 = max(L2, 0ll);

    	ans += (ll) (L1-L2) * (R1 - pos[i]) * i;
    	ans += (ll) (R2-R1) * (pos[i] - L1) * i;

    	s.insert(pos[i]);
    }

    cout << ans << "\n";
	
    return 0;
}
