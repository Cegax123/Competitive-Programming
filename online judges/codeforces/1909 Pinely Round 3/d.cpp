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
        ll k; cin >> k;
        ll a[n];
        ll g = 0;
        bool cmp = true;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            g = __gcd(g, a[i]-k);
            if(a[i] == k) cmp = false;
        }

        if(*min_element(a, a+n) == *max_element(a, a+n)) {
            cout << 0 << "\n";
            continue;
        }

        if(!cmp) {
            cout << -1 << "\n";
            continue;
        }
        
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            if((a[i]-k) / g <= 0) cmp = false;
            ans += (a[i]-k)/g-1;
        }

        if(!cmp) cout << -1 << "\n";
        else cout << ans << "\n";
    }

	
    return 0;
}


