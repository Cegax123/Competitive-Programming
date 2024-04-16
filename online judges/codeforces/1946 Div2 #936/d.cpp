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
        int n, x; cin >> n >> x;
        vector<int> a(n);
        vector<int> pa(n);

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(i == 0) pa[i] = a[i];
            else pa[i] = pa[i-1] ^ a[i];
        }

        if(pa[n-1] > x) {
            cout << -1 << "\n";
            continue;
        }

        auto is_submask = [](int s, int m) {
            if((m&s) == s) return true;
            return false;
        };
        
        auto get_ans = [&](int lmt, int j) {
            int cnt = 0;
            int last = 0;

            for(int i = 0; i < n-1; i++) {
                if(is_submask((pa[i] ^ last)>>j, lmt>>j)) {
                    cnt++;
                    last = pa[i];
                }
            }

            if(is_submask((pa[n-1] ^ last) >> j, lmt>>j)) return cnt+1;
            return -1;
        };

        int ans = get_ans(x, 0);

        for(int i = 0; i < 30; i++) {
            if((x>>i)&1) {
                ans = max(ans, get_ans(x^(1<<i), i));
            }
        }
        cout << ans << "\n";
    }

	
    return 0;
}


