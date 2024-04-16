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
    const ll mod = 1e9 + 7;
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n], b[n];

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        sort(a, a+n);
        sort(b, b+n);

        int ind[n];
        int pos = 0;

        for(int i = 0; i < n; i++) {
            while(pos < n and b[pos] < a[i]) {
                pos++;
            }

            ind[i] = pos;
        }

        int ans = 1;
        for(int i = 0; i < n; i++) {
            if(ind[i] - i <= 0) ans = 0;
            else ans = (ans * 1ll * (ind[i]-i)) % mod;
        }

        cout << ans << "\n";
    }

	
    return 0;
}


