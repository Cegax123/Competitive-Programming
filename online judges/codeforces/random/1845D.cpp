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
        for(int i = 0; i < n; i++) cin >> a[i];
 
        ll r[n];
        r[n-1] = max(0ll, (ll) a[n-1]);
 
        ll carry = min(0ll, (ll) a[n-1]);
 
        for(int i = n-2; i >= 0; i--) {
            if(r[i] < 0) {
                r[i] = r[i+1];
                carry += r[i];
            }
            else {
                r[i] = r[i+1] + max(0ll, carry + a[i]);
                carry = min(0ll, carry + a[i]);
            }
        }
 
        ll ans = 0;
        ll sum = 0;
        ll res = 0;
 
        for(int i = 0; i < n; i++) {
            if(ans < sum + r[i]) {
                ans = sum + r[i];
                res = sum;
            }
            sum += a[i];
        }

        if(ans < sum) {
            ans = sum;
            res = (ll) 1e18;
        }
 
        cout << res << "\n";
    }
 
	
    return 0;
}
