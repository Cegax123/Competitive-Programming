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
            if(i) a[i] += a[i-1];
        }

        int q; cin >> q;
        while(q--) {
            int l, u; cin >> l >> u;
            l--;

            int L = l, R = n-1;
            while(L < R) {
                int M = (L+R+1) >> 1;
                int sum = a[M]-(l == 0 ? 0 : a[l-1]);

                if(sum <= u) L = M;
                else R = M-1;
            }

            int sum = a[L] - (l == 0 ? 0 : a[l-1]);

            auto get = [&](int a, int u) {
                int x = u;
                int y = u - a + 1;
                y = abs(y);

                return x * 1ll * (x+1) / 2 - y * 1ll * (y+1) / 2;
            };

            int r = L;
            if(sum < u) {
                int x = a[L+1] - a[L];
                if(L+1 < n and get(x, u-sum) > 0) r++;
            }

            cout << r+1 << " ";
        }
        cout << "\n";
    }

	
    return 0;
}


