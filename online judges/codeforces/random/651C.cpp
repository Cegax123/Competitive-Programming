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

ll f(ll x) {
    return (x * (x-1)) / 2;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    map<int, int> X, Y;
    map<ii, int> XY;

    int n; cin >> n;
	
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        X[x]++;
        Y[y]++;
        XY[{x, y}]++;
    }

    ll ans = 0;

    for(auto& el : X) 
        ans += f(el.second);

    for(auto& el : Y)
        ans += f(el.second);

    for(auto& el : XY)
        ans -= f(el.second);

    cout << ans << "\n";
	
	return 0;
}

