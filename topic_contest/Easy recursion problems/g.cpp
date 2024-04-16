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

ll sum(ll x) {
    return x * (x+1) / 2;
}

ll sumdig(ll n) {
    ll sum = 0;

    while(n) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

ll f(ll n) {
    if(n <= 0) return 0;
    ll d = n % 10;
    return sum(d) + sum(9) * (n/10) + f(n/10);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll l, r; 
    while(cin >> l >> r and l >= 0) {
        cout << f(r) - f(l-1) << "\n";
    }

	
    return 0;
}


