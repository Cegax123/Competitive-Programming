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

const int maxn = 1e6;
const ll mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    vector<ll> a(maxn), b(maxn);

    a[1] = 1;
    b[1] = 1;

    for(int i = 2; i <= maxn; i++) {
        a[i] = (2 * a[i-1] + b[i-1]) % mod;
        b[i] = (4 * b[i-1] + a[i-1]) % mod;
    }

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        ll ans = (a[n] + b[n]) % mod;
        cout << ans << "\n";
    }
	
	return 0;
}

