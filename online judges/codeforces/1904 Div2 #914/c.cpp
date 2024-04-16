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
        int n, k; cin >> n >> k;
        ll a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        if(k >= 3) {
            cout << 0 << "\n";
            continue;
        }
        sort(a, a+n);

        ll ans = (ll) 2e18;

        for(int i = 0; i < n; i++)
            ans = min(ans, a[i]);

        for(int i = 1; i < n; i++)
            ans = min(ans, abs(a[i]-a[i-1]));

        if(k == 1) {
            cout << ans << "\n";
            continue;
        }

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                ll diff = abs(a[i]-a[j]);

                int l = 0, r = n-1;
                while(l < r) {
                    int m = (l+r+1) >> 1;
                    if(a[m] <= diff) l = m;
                    else r = m-1;
                }
                if(a[l] <= diff) ans = min(ans, diff-a[l]);

                l = 0, r = n-1;

                while(l < r) {
                    int m = (l+r) >> 1;
                    if(a[m] >= diff) r = m;
                    else l = m+1;
                }

                if(a[l] >= diff) ans = min(ans, a[l]-diff);
            }
        }

        cout << ans << "\n";
    }

	
    return 0;
}


