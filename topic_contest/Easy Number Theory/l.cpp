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

int ex(int a, int b, int c) {
    int ans = 1;

    while(b) {
        if(b&1) ans = ans * 1ll * a % c;
        a = a * 1ll * a % c;
        b >>= 1;
    }

    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        cout << "Case " << tt << ": ";
        int n, k, mod; cin >> n >> k >> mod;
        int sum = 0;

        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            x %= mod;
            sum = (sum + x) % mod;
        }

        cout << ex(n, k-1, mod) * 1ll * k % mod * sum % mod << "\n";
    }

	
    return 0;
}


