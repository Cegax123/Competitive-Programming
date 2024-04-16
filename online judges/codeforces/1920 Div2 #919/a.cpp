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
        int l = 0, r = 2e9;
        set<int> banned;

        for(int i = 0; i < n; i++) {
            int op; cin >> op;
            if(op == 1) {
                int x; cin >> x;
                l = max(l, x);
            }
            else if(op == 2) {
                int x; cin >> x;
                r = min(r, x);
            }
            else {
                int x; cin >> x;
                banned.insert(x);
            }
        }

        if(r < l) {
            cout << 0 << "\n";
            continue;
        }

        int ans = r-l+1;

        for(int x : banned) if(l <= x and x <= r) ans--;

        cout << ans << "\n";
    }

	
    return 0;
}


