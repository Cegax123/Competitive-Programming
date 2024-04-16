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
        ll n, k; cin >> n >> k;
        if(n < k) {
            cout << "NO\n";
            continue;
        }

        if(n == k) {
            cout << "YES\n";
            cout << 1 << "\n" << 1 << "\n";
        }
        else if(n >= 2 * k - 1) {
            ll x = n - k;
            cout << "YES\n";
            cout << 2 << "\n";
            cout << x+1 << " " << 1 << "\n";
        }
        else cout << "NO\n";
    }

	
    return 0;
}


