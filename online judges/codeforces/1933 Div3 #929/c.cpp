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
        int a, b, l; cin >> a >> b >> l;

        vector<int> ans;
        for(int x = 0; x <= 20; x++) {
            for(int y = 0; y <= 20; y++) {
                int t1 = 1;
                for(int i = 0; i < x; i++) {
                    t1 *= a;
                    if(t1 > l) break;
                }

                int t2 = 1;
                for(int i = 0; i < y; i++) {
                    t2 *= b;
                    if(t2 > l) break;
                }

                if(t1 > l or t2 > l) continue;

                if(t1 * 1ll * t2 <= l) {
                    if(l % (t1 * t2) == 0) ans.pb(l / (t1 * t2));
                }
            }
        }
        sort(all(ans));
        ans.erase(unique(all(ans)), ans.end());

        cout << ans.size() << "\n";
    }

	
    return 0;
}


