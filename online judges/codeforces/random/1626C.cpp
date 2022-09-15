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

ll tri(ll x) {
    return x * (x+1ll) / 2ll;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int k[n], h[n];

        for(int i = 0; i < n; i++)
            cin >> k[i];
        for(int i = 0; i < n; i++)
            cin >> h[i];

        ll ans = 0;

        int L = 1e9+5;
        int R = L;

        for(int i = n-1; i >= 0; i--) {
            if(k[i] >= L) {
                L = min(L, k[i]-h[i]+1);
            }
            else {
                ans += tri(R-L+1);

                L = k[i]-h[i]+1;
                R = k[i];
            }
        }

        ans += tri(R-L+1)-1;
        cout << ans << "\n";
    }
	
	
	return 0;
}

