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
        ll n, m; cin >> n >> m;

        if(n == 1 or m == 1) {
            if(n == 1 and m == 1) cout << 0;
            else if(n == 2 or m == 2) cout << 1;
            else cout << -1;

            cout << "\n";
            
            continue;
        }

        ll ans = 2 * min(n-1, m-1);
        ll x = max(n, m) - min(n, m);

        ans += (x+1)/2 + x / 2 * 3;

        cout << ans << "\n";
    }

	
    return 0;
}


