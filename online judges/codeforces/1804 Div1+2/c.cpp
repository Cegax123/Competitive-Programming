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
        ll n; cin >> n;
        ll x, p; cin >> x >> p;

        p = min(p, 3 * n);

        ll curr = 0;
        bool ans = 0;
        for(int i = 1; i <= p; i++) {
            curr += i;
            curr %= n;

            if((x + curr) % n == 0) ans = 1;
        }

        cout << (ans ? "Yes\n" : "No\n");
    }

	
    return 0;
}


