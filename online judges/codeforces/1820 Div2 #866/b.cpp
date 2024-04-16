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
        string s; cin >> s;
        int n = s.size();
        s += s;

        int ind = 0;

        int mx = 0;

        while(ind < (int) s.size()) {
            if(s[ind] == '0') {
                ind++;
                continue;
            }

            int r = ind;
            while(r < (int) s.size() and s[r] == s[ind]) {
                r++;
            }

            mx = max(mx, min(n, r-ind));
            ind = r;
        }

        if(mx == n) cout << n * 1ll * n << "\n";
        else {
            ll a = (mx+1) / 2, b = mx+1 - a;
            cout << a * b << "\n";
        }
    }

	
    return 0;
}


