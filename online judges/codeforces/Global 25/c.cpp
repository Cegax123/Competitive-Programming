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
        int n, m, k; cin >> n >> m >> k;
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a+n);

        ll ans = 0;
        ll sum = 0;
        vector<int> pos;
        for(int i = 0; i < n; i++) {
            int need = min(k, m);
            ans += sum * 1ll * need;
            ans += need * 1ll * a[i];
            sum += need;
            k -= need;
        }

        cout << ans << "\n";
    }

	
    return 0;
}


