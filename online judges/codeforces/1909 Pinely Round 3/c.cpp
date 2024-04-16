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
        int l[n], r[n], c[n];
        for(int i = 0; i < n; i++) cin >> l[i];
        for(int i = 0; i < n; i++) cin >> r[i];
        for(int i = 0; i < n; i++) cin >> c[i];

        sort(l, l+n);
        sort(r, r+n);
        sort(c, c+n);

        stack<int> st;
        int ind = 0;

        int d[n];

        for(int i = 0; i < n; i++) {
            while(ind < n and l[ind] < r[i]) {
                st.push(l[ind]);
                ind++;
            }
            d[i] = r[i] - st.top();
            st.pop();
        }

        ll ans = 0;
        sort(d, d+n);
        reverse(d, d+n);

        for(int i = 0; i < n; i++) {
            ans += d[i] * 1ll * c[i];
        }

        cout << ans << "\n";
    }

	
    return 0;
}


