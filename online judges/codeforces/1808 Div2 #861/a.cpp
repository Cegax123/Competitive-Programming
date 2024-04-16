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
        int l, r; cin >> l >> r;
        if(r-l >= 200) {
            if((l / 100) * 100 + 90 >= l) {
                cout << (l/100) * 100 + 90 << "\n";
            }
            else {
                cout << (l / 100 + 1) * 100 + 90 << "\n";
            }
        }
        else {
            int ans = -1;
            int luck = -1;

            for(int i = l; i <= r; i++) {
                int tmp = i;
                int maxd = -1, mind = 10;

                while(tmp) {
                    maxd = max(maxd, tmp%10);
                    mind = min(mind, tmp%10);
                    tmp /= 10;
                }

                if(maxd-mind > luck) {
                    luck = maxd-mind;
                    ans = i;
                }
            }
            cout << ans << "\n";
        }
    }

	
    return 0;
}


