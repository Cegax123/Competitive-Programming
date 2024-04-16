#include <iostream>
#include <vector>
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

ll gcd(ll a, ll b) {
    if(a < b) swap(a, b);
    if(b == 0) return a;
    return gcd(b, a % b);
}

// min k : a * k + b * q = c
ll solve(ll a, ll b, ll c) {
    ll g = gcd(a, b);
    
    if(c % g) {
        return -1;
    }

    a /= g;
    b /= g;

    ll x, y;
    bezout(a, b, x, y);

    x *= c / g;

    if(x < 0) {
        ll tmp = -x;
        tmp = ((tmp + b - 1)/ b) * b;
        x += tmp;
    }

    x %= b;

    return x;
}

ll norma(ll a, ll mod) {
    if(a < 0) {
        ll b = -a;
        b = ((b + mod - 1)/ mod) * mod;
        a += b;
    }

    a %= mod;

    return a;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll x, y, m, n, L; cin >> x >> y >> m >> n >> L;

    if(m == n) {
        ll c = norma(x-y, L);

        if(c == 0) cout << 0 << "\n";
        else cout << "Impossible\n";

        return 0;
    }

    ll c = norma(x-y, L);
    ll a = norma(n-m, L);

    ll k = solve(a, L, c);

    if(k == -1) cout << "Impossible\n";
    else cout << k << "\n";
	
    return 0;
}


