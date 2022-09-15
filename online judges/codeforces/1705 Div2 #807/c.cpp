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
        int n, c, q; cin >> n >> c >> q;
        string s; cin >> s;

        ll l[c+1], r[c+1], sum[c+1];
        l[0] = 1, r[0] = n, sum[0] = n;

        for(int i = 1; i <= c; i++) {
            cin >> l[i] >> r[i];

            ll L = r[i]-l[i]+1ll;
            sum[i] = sum[i-1] + L;
        }

        while(q--) {
            ll k; cin >> k;

            while(k > n) {
                int ind = 0;
                while(sum[ind] < k) 
                    ind++;

                k -= sum[ind-1];
                k = l[ind] + k - 1;
            }

            cout << s[k-1] << "\n";
        }
    }

	
    return 0;
}


