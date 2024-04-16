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
    int tc; cin >> tc;
    while(tc--) {
        int n, k; cin >> n >> k;
        int L[n], R[n];
        for(int i = 0; i < n; i++) cin >> L[i];
        for(int i = 0; i < n; i++) cin >> R[i];

        int d[n];
        for(int i = 0; i < n; i++)
            d[i] = R[i]-L[i]+1;

        int ans = (int) 2e9;

        int sum = 0;
        multiset<int> s;

        for(int i = 0; i < n; i++) {
            int need = k-sum;

            if(need <= d[i] and need > 0) {
                ans = min(ans, 2 * ((int) s.size() + 1) + (L[i] + need - 1));
            }
            
            while(true) {
                if(s.empty()) break;
                int x = *s.begin();

                need = k-(sum-x);
                if(need <= d[i] and need > 0) {
                    ans = min(ans, 2 * ((int) s.size()) + (L[i] + need - 1));

                    s.erase(s.begin());
                    sum -= x;
                }
                else break;
            }
            s.insert(d[i]);
            sum += d[i];

            while(true) {
                int x = *s.begin();
                if(sum - x >= k) {
                    s.erase(s.begin());
                    sum -= x;
                }
                else break;
            }
        }

        if(ans == (int) 2e9) cout << -1 << "\n";
        else cout << ans << "\n";
    }

	
    return 0;
}


