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

ll ans = 0;
ll l, r;

ll f(ll x) {
    ll ans = 0;

    for(int i = 60; i > 0; i--) {
        if((x>>i)&1ll) {
            ans |= ((((x&((1ll<<i)-1))+1)&1) << i);
        }
    }

    if((x%4)==1 or (x%4) == 2) ans ^= 1;

    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll l, r; cin >> l >> r;

	cout << (l == 0 ? f(r) : (f(r) ^ f(l-1))) << "\n";

    return 0;
}


