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

    auto sqrtn = [](ll n) {
        int l = 0, r = 1e6;
        while(l < r) {
            int m = (l+r+1) >> 1;
            if(m * 1ll * m <= n) l = m;
            else r = m-1;
        }

        return l;
    };

    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        ll n; cin >> n;

        cout << "Case " << tc << ": ";
        cout << n - sqrtn(n) - sqrtn(n/2) << "\n";
    }

	
    return 0;
}


