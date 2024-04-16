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
        int n, m; cin >> n >> m;
        vi a[m];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int x; cin >> x;
                a[j].pb(x);
            }
        }

        ll ans = 0;
        for(int j = 0; j < m; j++) {
            sort(all(a[j]));

            for(int i = 0; i < n; i++) {
                ans -= a[j][i] * 1ll * ((n-1-i) - i);
            }
        }
        cout << ans << "\n";
    }

	
    return 0;
}


