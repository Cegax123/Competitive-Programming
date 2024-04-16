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

int ex(ll a, ll b, ll c) {
    ll ans = 1;

    while(b) {
        if(b&1) ans = ans * a % c;
        a = a * a % c;
        b >>= 1;
    }

    return ans;
}

int main() {
    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        int n, k; cin >> n >> k;

        double l = log10(n * 1.0) * k;
        l -= floor(l);
        int L = pow(10, l) * 100;

        cout << "Case " << tc << ": ";
        cout << L << " ";
        printf("%03d\n", ex(n % 1000, k, 1000));
    }

	
    return 0;
}


