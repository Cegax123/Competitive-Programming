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
    int t; cin >> t;
    while(t--) {
        ll a, b, c; cin >> a >> b >> c;

        for(int i = 0; i < 40; i++) {
            if(a == b and b == c) break;
            int ba = (a >> i)&1;
            int bb = (b >> i)&1;
            int bc = (c >> i)&1;

            if(ba == bc and ba == bb)
                break;

            if(ba + bb + bc == 1) {
                if(ba == 1) a += (1ll << i);
                if(bb == 1) b += (1ll << i);
                if(bc == 1) c += (1ll << i);
            }
            else {
                if(ba == 0) a += (1ll << i);
                if(bb == 0) b += (1ll << i);
                if(bc == 0) c += (1ll << i);
            }
        }

        if(a == b and b == c)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

	
    return 0;
}


