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
        ll s; cin >> s;
        ll a[n];

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for(int i = 1; i+1 < n; i++) {
            a[i] -= s;
        }

        ll sum = 0;

        for(int i = 0; i < n; i++)
            sum += a[i] * s;

        const ll INF = (ll) 1e18;
        ll ans = INF;

        for(int i = 0; i+1 < n; i++) {
            ans = min(ans, sum - (a[i] + a[i+1]) * s + a[i] * a[i+1] * s);
        }

        cout << ans << "\n";
    }



	
    return 0;
}


