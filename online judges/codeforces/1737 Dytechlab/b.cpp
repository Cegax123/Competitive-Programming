#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
typedef unsigned long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//cout << setprecision(12) << fixed;

ll get_num(ll n) {
    ll k = (n-1)/3 + 1;
    ll x = k + (n % 3) - 1 + (n % 3 == 0 ? 3 : 0);

    return k * x;
}

ll get_lmt(ll n) {
    if(n == 0) return 0;
    ll l = 1, r = (ll) 4e9+1000;

    while(l < r) {
        ll m = (l+r+1) >> 1;
        if(get_num(m) <= n) l = m;
        else r = m-1;
    }

    return l;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int TT;
    cin >> TT;

    while(TT--) {
        ll l, r; cin >> l >> r;

        
        cout << get_lmt(r) - get_lmt(l-1) << "\n";
    }

	
    return 0;
}


