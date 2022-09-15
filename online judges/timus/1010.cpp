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
    ll a[n+1];

    for(int i = 1; i <= n; i++) 
        cin >> a[i];

    int ans = 1;
    ll max_inclination = abs(a[2]-a[1]);

    for(int i = 3; i <= n; i++) {
        if(max_inclination < abs(a[i]-a[i-1])) {
            max_inclination = abs(a[i]-a[i-1]);
            ans = i-1;
        }
    }

    cout << ans << " " << ans + 1 << "\n";

    return 0;
}


