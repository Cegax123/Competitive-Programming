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
    vi a(n);
    ll ans = 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ans += abs(a[i]-1);
    }

    sort(all(a));

    for(int c = 2; c <= 1e5; c++) {
        vector<ll> v(1, 1);

        while(v.back() < 1e10) {
            v.pb(v.back() * c);
        }

        if((int) v.size() >= n) {
            ll curr = 0;
            for(int i = 0; i < n; i++) {
                curr += abs(a[i]-v[i]);
            }
            ans = min(ans, curr);
        }

    }

	
    cout << ans << "\n";
    return 0;
}


