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
    const int L = 60;

    int t; cin >> t;
    while(t--) {
        int n, q; cin >> n >> q;

        int sum[n+1][L];
        memset(sum, 0, sizeof(sum));

        for(int i = 1; i <= n; i++) {
            ll a; cin >> a;
            for(int j = 0; j < L; j++) {
                if((a >> j)&1ll) {
                    sum[i][j] = 1;
                }
            }
        }

        for(int j = 0; j < L; j++) {
            for(int i = 1; i <= n; i++) {
                sum[i][j] += sum[i-1][j];
            }
        }

        auto get_1 = [&](int l, int r, int k) {
            return sum[r][k] - sum[l-1][k];
        };

        auto get_0 = [&](int l, int r, int k) {
            return r-l+1 - get_1(l, r, k);
        };

        while(q--) {
            int k, l1, r1, l2, r2; cin >> k >> l1 >> r1 >> l2 >> r2;
            ll L0 = get_0(l1, r1, k), L1 = get_1(l1, r1, k);
            ll R0 = get_0(l2, r2, k), R1 = get_1(l2, r2, k);

            cout << L0 * R1 + R0 * L1 << "\n";
        }
    }

	
    return 0;
}


