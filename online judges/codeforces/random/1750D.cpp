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
        int a[n];
        bool cmp = 1;

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(i) {
                if(a[i-1] % a[i]) cmp = 0;
            }
        }

        if(!cmp) {
            cout << 0 << "\n";
            continue;
        }

        const ll mod = 998244353;
        ll ans = 1;
        for(int i = 1; i < n; i++) {
            ll q = m / a[i];
            ll r = a[i-1] / a[i];

            if(r == 1) {
                ans = ans * q % mod;
                continue;
            }

            ll tmp = r;
            vector<ll> div;
            
            for(int j = 2; j * j <= tmp; j++) {
                if(r % j == 0) {
                    div.pb(j);
                    while(r % j == 0) r /= j;
                }
            }

            if(r > 1) div.pb(r);

            int k = div.size();
            ll curr = 0;

            //cout << i << ": ";

            //for(int x : div) cout << x << " ";
            //cout << endl;

            for(int mask = 0; mask < (1 << k); mask++) {
                ll num = 1;

                int sum = 0;
                for(int j = 0; j < k; j++) {
                    if((mask >> j)&1) {
                        num *= div[j];
                        sum++;
                    }
                }

                if(sum&1) curr -= q / num;
                else curr += q / num;
            }

            ans = ans * curr % mod;
        }

        cout << ans << "\n";
    }

	
    return 0;
}


