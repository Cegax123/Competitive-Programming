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
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int ans = 0;
        for(int d = 1; d <= n; d++) {
            if(n%d) continue;
            if(d == n) {
                ans++;
                continue;
            }
            int m = 0;
            for(int k = 0; k < d; k++) {
                for(int j = 1; j < n/d; j++) {
                    m = __gcd(m, abs(a[k+j*d] - a[k]));
                }
            }

            if(m > 1 or m == 0) ans++;
        }

        cout << ans << "\n";
    }

	
    return 0;
}


