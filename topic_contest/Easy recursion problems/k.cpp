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

int ans = 0;
map<ll, ll> sz;

ll get_size(ll n) {
    if(n <= 1) {
        return sz[n] = 1;
    }
    return sz[n] = get_size(n/2) * 2 + 1;
}

ll get_ans(ll n, ll l, ll r) {
    //cout << n << " " << l << " " << r << endl;
    if(n <= 1) return n == 1;

    ll ans = 0;
    if(l <= sz[n/2]) {
        ans += get_ans(n/2, l, min(r, sz[n/2]));
    }

    if(r >= sz[n/2]+1 and l <= sz[n/2]+1) ans += (n&1);

    if(r > sz[n/2] + 1) {
        ans += get_ans(n/2, max(1ll, l-sz[n/2]-1), r-sz[n/2]-1);
    }

    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n, l, r; cin >> n >> l >> r;

    get_size(n);
    cout << get_ans(n, l, r) << "\n";
	
    return 0;
}


