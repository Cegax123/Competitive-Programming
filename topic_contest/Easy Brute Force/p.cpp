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
    ll n, k; cin >> n >> k;
    ll a[n], b[n];

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    ll ans = 0;

    for(ll can = 1; can <= 3000; can++) {
        ll needed = 0;
        for(int i = 0; i < n; i++) {
            needed += max(0ll, can * a[i] - b[i]);
        }

        if(needed <= k) ans = can;
    }

    cout << ans << "\n";
	
    return 0;
}


