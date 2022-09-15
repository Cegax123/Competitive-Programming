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
	int n; cin >> n;
    ll a[n];

    for(int i = 0; i < n; i++) 
        cin >> a[i];

    ll ans = -1;

    for(int i = 0; i < n; i++) {
        ll local = 0;

        if(i + 1 < n) {
            local++;
            ll R = a[i+1];

            for(int j = i+2; j < n; j++) {
                ll add = R / a[j] + 1;
                local += add;

                R = add * a[j];
            }
        }

        if(i) {
            local++;
            ll L = a[i-1];

            for(int j = i-2; j >= 0; j--) {
                ll add = L / a[j] + 1;
                local += add;

                L = add * a[j];
            }
        }

        if(ans == -1) ans = local;
        ans = min(ans, local);
    }

    cout << ans << "\n";
	
    return 0;
}


