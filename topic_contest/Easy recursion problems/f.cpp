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

ll justone(ll n) {
    int cnt = 0;
    while(n) {
        if(n % 10 == 0) cnt++;
        n /= 10;
    }

    return cnt;
}

ll f(ll n) {
    if(n <= 9) return 0;

    ll d = n%10;
    return n/10 + justone(n/10) * (d+1) + 10ll * f(n/10 - 1);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll l, r;
    while(cin >> l >> r and (l >= 0)) {
        cout << f(r) - f(l-1)+(l == 0) << "\n";
    }

	
    return 0;
}


