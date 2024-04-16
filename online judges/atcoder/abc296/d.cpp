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
    ll n, m; cin >> n >> m;

    ll ans = -1;

    for(ll i = 1; i <= (ll) 1e7; i++) {
        ll b = (m+i-1) / i;

        if(i <= n and b <= n) {
            if(ans == -1) ans = i * b;
            ans = min(ans, i * b);
        }
    }

    cout << ans << "\n";
	
    return 0;
}


