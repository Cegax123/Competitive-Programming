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
    int q; cin >> q;
    while(q--) {
        ll t; int x, y; cin >> t >> x >> y;

        if(t < x + y) {
            cout << "NO\n";
            continue;
        }

        if(t == 0) {
            if(x+y == 0) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }

        const int len = 120;

        auto f = [&](vector<vector<ll>>& a, ll init) {
            a[0][0] = init;

            for(int i = 0; i < len; i++) {
                for(int j = 0; j < len; j++) {
                    int toR = (a[i][j]+1)/2, toL = a[i][j]/2;

                    if(i+j+1 < init) a[i][j+1] += toR;
                    if(i+j+1 < init) a[i+1][j] += toL;
                }
            }
        };

        vector<vector<ll> > a(len+1, vector<ll>(len+1, 0)), b(len+1, vector<ll>(len+1, 0));

        f(a, t-1);
        f(b, t);

        if(a[x][y] != b[x][y]) cout << "YES\n";
        else cout << "NO\n";
        
    }

	
    return 0;
}


