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
        int k; cin >> k;
        k--;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int T = a[k];

        auto get = [&]() {
            int ans = 0;
            int w = a[0];
            for(int i = 1; i < n; i++) {
                w = max(w, a[i]);
                if(w == T) ans++;
            }
            return ans;
        };

        swap(a[k], a[0]);
        int ans = get();

        swap(a[k], a[0]);

        for(int i = 0; i < n; i++) {
            if(a[i] > a[k]) {
                swap(a[i], a[k]);
                ans = max(ans, get());
                swap(a[i], a[k]);
                break;
            }
        }

        cout << ans << "\n";
    }

	
    return 0;
}


