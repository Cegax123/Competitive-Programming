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
    ll x, y, z; 
    char op, eq; 
    cin >> x >> op >> y >> eq >> z;

    auto find_cd = [](ll x) {
        int ans = 0;
        while(x) {
            ans++;
            x /= 10;
        }
        return ans;
    };

    auto get = [](ll x, ll y, char op) {
        if(op == '+') return x + y;
        else return x * y;
    };

    auto change = [&](ll x, ll y, ll px, ll py) {
        ii ans;

        int cdx = find_cd(x);
        ll p10x = 1;

        for(int i = 0; i < cdx-px; i++)
            p10x *= 10;

        int cdy = find_cd(y);
        ll p10y = 1;

        for(int i = 0; i < cdy-py; i++)
            p10y *= 10;

        ll prefx = x / p10x, sufx = x % p10x;
        ll prefy = y / p10y, sufy = y % p10y;
        x = sufx + prefy * p10x;
        y = sufy + prefx * p10y;

        if(x <= (1ll << 31) and y <= (1ll << 31)) ans = {x, y};
        else ans = {-1, -1};
        return ans;
    };

    int cdx = find_cd(x), cdy = find_cd(y), cdz = find_cd(z);

    for(int i = 1; i < cdx; i++) {
        for(int j = 1; j < cdy; j++) {
            ii ans = change(x, y, i, j);
            if(ans.first == -1) continue;

            if(get(ans.first, ans.second, op) == z) {
                cout << ans.first << " " << op << " " << ans.second << " = " << z << "\n";
                return 0;
            }
        }
    }

    for(int i = 1; i < cdx; i++) {
        for(int k = 1; k < cdz; k++) {
            ii ans = change(x, z, i, k);

            if(ans.first == -1) continue;

            if(get(ans.first, y, op) == ans.second) {
                cout << ans.first << " " << op << " " << y << " = " << ans.second << "\n";
                return 0;
            }
        }
    }
	
    for(int j = 1; j < cdy; j++) {
        for(int k = 1; k < cdz; k++) {
            ii ans = change(y, z, j, k);

            if(ans.first == -1) continue;

            if(get(x, ans.first, op) == ans.second) {
                cout << x << " " << op << " " << ans.first << " = " << ans.second << "\n";
                return 0;
            }
        }
    }
    return 0;
}


