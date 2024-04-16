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
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a+n);
    
        vector<int> cnt(n+1, 0);

        ll ans = 0;
        int ind = 0;
        while(ind < n) {
            int r = ind;
            while(r < n and a[r] == a[ind]) {
                r++;
            }

            r--;

            int len = r-ind+1;

            if(len >= 3) {
                ans += len * 1ll * (len-1) * (len-2) / 6;
            }
            if(len >= 2) {
                ans += len * 1ll * (len-1) / 2 * ind;
            }

            ind = r + 1;
        }

        cout << ans << "\n";
    }

	
    return 0;
}


