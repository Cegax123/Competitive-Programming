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
    for(int tc = 1; tc <= t; tc++) {
        cout << "Case " << tc << ": ";
        ll n; cin >> n;
        ll ans = 0;
        
        ll lmt = 0;
        ll r = 0;

        for(int i = 1; i * 1ll * i <= n; i++) {
            ans += n / i;

            lmt = n / i;
            r = i;
        }

        while(r > 0 and n / r == lmt) {
            ans -= lmt;
            r--;
        }

        ll bef = n+1;
        for(int i = 1; i <= lmt; i++) {
            ll l = n / (i+1) + 1;
            if(l < bef) {
                ans += i * 1ll * (bef-l);
                bef = l;
            }
        }

        cout << ans << "\n";
    }

	
    return 0;
}


