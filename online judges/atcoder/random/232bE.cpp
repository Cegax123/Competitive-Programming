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

void print_board(const vector<vi>& b) {
    for(auto v : b) {
        for(auto x : v) 
            cout << x << " ";
        cout << "\n";
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n, m, k; cin >> n >> m >> k;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

    const ll mod = 998244353;

    x1--; y1--; x2--; y2--;
    
    ll c, o, h, v;
    c = 1; o = h = v = 0;

    for(int i = 0; i < k; i++) {
        ll nc = (n-1) * v % mod + (m-1) * h % mod;
        ll no = (n-2) * o % mod + (m-2) * o % mod + v + h;
        ll nh = c + (m-2) * h % mod + (n-1) * o % mod;
        ll nv = c + (n-2) * v % mod + (m-1) * o % mod;

        c = nc % mod;
        o = no % mod;
        v = nv % mod;
        h = nh % mod;
    }

    if(x1 == x2 and y1 == y2) 
        cout << c << "\n";
    else if(x1 == x2)
        cout << h << "\n";
    else if(y1 == y2) 
        cout << v << "\n";
    else
        cout << o << "\n";
	
    return 0;
}


