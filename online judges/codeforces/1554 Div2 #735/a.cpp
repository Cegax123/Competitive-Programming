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
        ll a0 = 0, a1 = 0;
        ll ans = 0;

        for(int i = 0; i < n; i++) {
            a0 = a1;
            cin >> a1;

            if(i >= 1) ans = max(ans, a0 * a1);
        }

        cout << ans << "\n";
    }

	
    return 0;
}


