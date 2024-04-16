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

ll f(ll n) {
    if(n == 1) return 2;
    int i = 0;
    while((1ll << i) <= n) {
        i++;
    }

    ll L = (1ll << (i-1)), R = (1ll << i) - 1;
    ll len = R-L+1;
    if(n < L + len / 2) return f(L / 2 + (n-L));
    return 2 * f(L/2 + (n-(L+len/2)));
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n; cin >> n;

    cout << f(n) << "\n";
	
    return 0;
}


