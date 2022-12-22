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
    int q; cin >> q;
    while(q--) {
        int n, k; cin >> n >> k;
        int a[n+1];
        for(int i = 1; i <= n; i++)
            cin >> a[i];

        int t = min(2000, n);

        const ll INF = (ll) 1e18;
        ll ans = -INF;
        for(ll x = n-t+1; x <= n; x++) {
            for(ll y = x+1; y <= n; y++) {
                ans = max(ans, x * y - k * (a[x] | a[y]));
            }
        }

        cout << ans << "\n";
    }

    return 0;
}


