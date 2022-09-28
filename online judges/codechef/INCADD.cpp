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
        const ll INF = (ll) 1e18;

        int n, q; cin >> n >> q;
        vector<ll> a(n+2);
        a[0] = -INF;
        a[n+1] = INF;

        for(int i = 1; i <= n; i++)
            cin >> a[i];

        multiset<ll> s;
        for(int i = 1; i <= n+1; i++) {
            s.insert(a[i]-a[i-1]);
        }

        auto dele = [&](ll x) {
            s.erase(s.find(x));
        };

        while(q--) {
            int i, x; cin >> i >> x;
            dele(a[i]-a[i-1]);
            dele(a[i+1]-a[i]);

            a[i] = x;
            s.insert(a[i]-a[i-1]);
            s.insert(a[i+1]-a[i]);

            int p = *s.begin();
            p = min(0, p);

            cout << -p << "\n";
        }
    }

	
    return 0;
}


