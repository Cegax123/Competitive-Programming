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
        int n, m; cin >> n >> m;
        n = abs(n);
        m = abs(m);

        if(n > m) swap(n, m);

        if(n == 0) {
            if(m == 0) cout << 0 << "\n";
            else cout << m + m - 1 << "\n";
            continue;
        }

        if(n == m or n+1 == m) cout << n + m << "\n";
        else {
            int ans = n + n + 1;
            m -= n+1;

            if(m&1) ans += m + m;
            else ans += 2 * m;


            cout << ans << "\n";
        }
    }

	
    return 0;
}


