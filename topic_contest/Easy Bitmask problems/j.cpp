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
        ll l, r; cin >> l >> r;
        ll pref = 0ll;
        int ind = -1;

        for(int i = 63; i >= 0; i--) {
            if(((l >> i)&1ll) == ((r >> i)&1ll)) {
                if((l >> i)&1ll)
                    pref |= (1ll << i);
            }
            else {
                ind = i;
                break;
            }
        }

        cout << "Case " << tc << ": ";
        if(ind == -1) cout << pref << " " << pref << "\n";
        else cout << (pref | ((1ll << ind)-1) | (1ll << ind)) << " " << pref << "\n";
    }

	
    return 0;
}



