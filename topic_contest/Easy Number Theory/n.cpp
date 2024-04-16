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

ll f(ll x) {
    ll ans = 0;

    while(x) {
        x /= 5;
        ans += x;
    }
    
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        int q; cin >> q;
        ll l = 1, r = 1e9;

        while(l < r) {
            ll m = (l+r) >> 1;
            if(f(m) >= q) r = m;
            else l = m+1;
        }

        cout << "Case " << tc << ": ";
        if(f(l) == q) cout << l << "\n";
        else cout << "impossible\n";
    }
	
    return 0;
}


