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
    ll a, m, l, r; cin >> a >> m >> l >> r;

    a %= m;
    if(a < 0) a += m;

    l -= a;
    r -= a;

    ll L = (l/m)*m;

    if(L < l) L += m;

    ll R = (r/m)*m;
    if(R > r) R -= m;

    if(L <= R) cout << (R-L)/m+1 << "\n";
    else cout << 0 << "\n";
	
    return 0;
}


