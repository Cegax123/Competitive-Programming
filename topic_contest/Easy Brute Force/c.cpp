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
  if (b == 0) { 
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
    ll n, a, b; cin >> n >> a >> b;

    ll g = __gcd(a, b);

    if(n % g) {
        cout << "NO\n";
        return 0;
    }

    a /= g;
    b /= g;
    n /= g;

    ll x, y;

    bezout(a, b, x, y);

    x *= n;
    y *= n;

    if(x < 0) {
        ll t = (abs(x)+b-1)/b;
        x += b * t;
        y -= a * t;
    }

    if(x > 0) {
        ll t = x / b;
        x -= b * t;
        y += a * t;
    }

    if(x >= 0 and y >= 0) {
        cout << "YES\n";
        cout << x << " " << y << "\n";
    }
    else cout << "NO\n";
	
    return 0;
}


