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
    ll l, r; cin >> l >> r;

    vector<ll> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    const int L = 60;

    bool pivoted[n];
    memset(pivoted, 0, sizeof(pivoted));

    for(int b = L-1; b >= 0; b--) {
        for(int i = 0; i < n; i++) {
            if(pivoted[i]) continue;
            if((a[i] >> b)&1ll) {
                for(int j = 0; j < n; j++) {
                    if(i == j) continue;
                    if((a[j] >> b)&1ll)
                        a[j] ^= a[i];
                }
                pivoted[i] = true;
                break;
            }
        }
    }

    sort(all(a));

    vector<ll> c;

    for(int i = 0; i < n; i++) {
        if(a[i]) c.pb(a[i]);
    }

    for(ll idx = l-1; idx <= r-1; idx++) {
        ll ans = 0;
        for(int j = 0; j < (int) c.size(); j++) {
            if((idx >> j)&1ll) ans ^= c[j];
        }

        cout << ans << " ";
    }
	
    return 0;
}


