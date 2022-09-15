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

ll bezout(ll a, ll b, ll& x_0, ll& y_0) {
  if (b == 0) { //solucion base a 1 + b 0 = a
    x_0 = 1;
    y_0 = 0;
    return a;
  }  
  ll x_1, y_1;
  ll g = bezout(b, a%b, x_1, y_1);
  x_0 = y_1;
  y_0 = x_1 - (a/b) * y_1;
  return g;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n; cin >> n;
    ll T = 0;

    vector<ll> c(n+1);

    for(int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        T += a;

        c[i] = (b-a);
    }

    c[0] = 2e9;

    sort(all(c));
    reverse(all(c));

    c[0] = 0;
    int lmt = 0;

    for(int i = 1; i <= n; i++) {
        if(c[i] >= 0) lmt = i;
        if(i) c[i] += c[i-1];
    }

    //cout << lmt << " " << lmt2 << endl;

    //for(int i = 0; i <= n; i++)
        //cout << c[i] << " ";

    int q; cin >> q;
    while(q--) {
        ll x, y; cin >> x >> y;

        ll tx = x, ty = y;

        ll g = __gcd(x, y);
        ll m = n;
        if(m%g) {
            cout << -1 << "\n";
            continue;
        }

        m /= g;
        x /= g;
        y /= g;

        ll cntx, cnty;

        bezout(x, y, cntx, cnty);
        cntx *= m;
        cnty *= m;

        if(cntx >= 0) {
            int k = cntx / y;
            cntx -= k * y;
            cnty += k * x;
        }
        else {
            int k = (-cntx + y-1) / y;
            cntx += k * y;
            cnty -= k * x;
        }

        if(cnty < 0) {
            cout << -1 << "\n";
            continue;
        }

        ll r = x * ty;

        ll R = cnty * ty;
        ll L = (cnty - (cnty/x) * x) * ty;

        ll t = (lmt-L) / r;
        ll P1 = L + t * r;
        ll P2 = L + (t + 1) * r;

        ll ans = max(T + c[L], T + c[R]);

        if(P1 >= L and P1 <= R) ans = max(ans, T + c[P1]);
        if(P2 >= L and P2 <= R) ans = max(ans, T + c[P2]);

        cout << ans << "\n";
    }

    return 0;
}


